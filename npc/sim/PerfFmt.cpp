#include "PerfCounter.hpp"
#include "spdlog/fmt/bundled/format.h"
#include "spdlog/spdlog.h"
#include <ostream>
#include <tabulate/table.hpp>

using namespace tabulate;

static void _SetTableFmt(Table &t) {
  assert(t.size() >= 2);
  t.format().font_align(FontAlign::right);
  t.row(0).format().font_align(FontAlign::center);

  for (auto &row : t) {
    row.format().hide_border_top();
  }

  t[0].format().show_border_top();
  t[1].format().show_border_top();
}
void _PrintTable(Table &t, std::ostream &os) {
  _SetTableFmt(t);
  os << t << std::endl;
}

void HandShakeCounterManager::dumpStatistics(std::ostream &os) {
  os << "handshake counts:\n";
  Table t;
  t.add_row({"Description", "Handshake Count", "Frequency"});
  for (auto &bus : bus_list) {
    double freq = sim_get_cycle() == 0
                      ? NAN
                      : ((double)bus.shake_count / (double)sim_get_cycle());
    t.add_row(RowStream{} << bus.description << bus.shake_count << freq);
  }
  _PrintTable(t, os);
}

const char *PipeStagePerfCounter::nameOfState(int s) {
  const char *names[] = {
      "Backpressure",
      "Bubble",
      "Fire",
  };
  return names[s];
}
void PipeStagePerfCounter::dumpStatistics(std::ostream &os) {
  spdlog::error("PipeStagePerfCounter::dumpStatistics unimpled!!!");
}
void PipePerfManager::dumpStatistics(std::ostream &os) {
  os << "Pipeline Performance Counter Statistics:\n";
  Table t;
  t.add_row({"Stage", "Backpressure\nCycles", "Bubble\nCycles", "Fire\nCycles",
             "Backpressure\n%", "Bubble\n%", "Fire\n%"});

  for (auto &ctr : stageCtrs) {
    size_t totCycles = ctr.totalCount();
    double backPerc =
        totCycles == 0
            ? NAN
            : ((double)ctr.countOfState[0] / (double)totCycles) * 100.0;
    double bubPerc =
        totCycles == 0
            ? NAN
            : ((double)ctr.countOfState[1] / (double)totCycles) * 100.0;
    double firePerc =
        totCycles == 0
            ? NAN
            : ((double)ctr.countOfState[2] / (double)totCycles) * 100.0;

    t.add_row(
        RowStream{} << ctr.ctrName
                    << ctr.countOfState[PipeStagePerfCounter::Backpressure]
                    << ctr.countOfState[PipeStagePerfCounter::Bubble]
                    << ctr.countOfState[PipeStagePerfCounter::Fire] << backPerc
                    << bubPerc << firePerc);
  }

  _PrintTable(t, os);
}
void RAWStallPerfCounter::dumpStatistics(std::ostream &os) {
  os << "RAW Stall Performance Counter Statistics:\n";
  double stallPerc =
      sim_get_cycle() == 0
          ? NAN
          : ((double)cycIDUStall / (double)sim_get_cycle()) * 100.0;
  os << "total RAW stall cycles: " << cycIDUStall << " (" << stallPerc
     << " %)\n";
  Table t;

  t.add_row({"Reason", "Stall Cycles", "Stall %\n(in tot)",
             "Stall %\n(in all stalls)"});
  auto addRow = [&](const char *reason, size_t cycles) {
    double percTot = sim_get_cycle() == 0
                         ? NAN
                         : ((double)cycles / (double)sim_get_cycle()) * 100.0;
    double percStall =
        cycIDUStall == 0 ? NAN : ((double)cycles / (double)cycIDUStall) * 100.0;
    t.add_row(RowStream{} << reason << cycles << percTot << percStall);
  };
  addRow("EXU conflict", cycConflictEXU);
  addRow("LSU conflict", cycConflictLSU);
  addRow("WBU conflict", cycConflictWBU);

  _PrintTable(t, os);
}

const char *IDUFlushPerfCounter::nameOfReason(int r) {
  static const char *name_of_reason[] = {"BranchTaken", "JALR",  "JAL",
                                         "Exception",   "Fence", "Unknown"};
  if (r < sizeof(name_of_reason) / sizeof(name_of_reason[0])) {
    return name_of_reason[r];
  } else {
    return "invalid reason";
  }
}
void IDUFlushPerfCounter::dumpStatistics(std::ostream &os) {
  os << "IDU Flush Performance Counter Statistics:\n";
  double flushPerc =
      sim_get_cycle() == 0
          ? NAN
          : ((double)cycIDUFlush / (double)sim_get_cycle()) * 100.0;
  os << "total IDU flush cycles: " << cycIDUFlush << " (" << flushPerc
     << " %)\n";
  Table t;
  t.add_row({"Reason", "Flush\nCycles", "Flush %\n(in tot)",
             "Flush %\n(in all flushes)"});

  for (int i = 0; i < REASON_NUM; i++) {
    double percTot =
        sim_get_cycle() == 0
            ? NAN
            : ((double)cycFlushOfReason[i] / (double)sim_get_cycle()) * 100.0;
    double percFlush =
        cycIDUFlush == 0
            ? NAN
            : ((double)cycFlushOfReason[i] / (double)cycIDUFlush) * 100.0;
    t.add_row(RowStream{} << nameOfReason(i) << cycFlushOfReason[i] << percTot
                          << percFlush);
  }
  _PrintTable(t, os);
}

const char *BranchPredPerfCounter::nameOf(int t) {
  static const char *name_of_type[] = {"Branch", "JAL", "JALR", "Exception"};
  if (t < sizeof(name_of_type) / sizeof(name_of_type[0])) {
    return name_of_type[t];
  } else {
    return "invalid type";
  }
}

void BranchPredPerfCounter::dumpStatistics(std::ostream &os) {
  os << "Branch Prediction Performance Counter Statistics:\n";

  size_t totBranchCount =
      std::accumulate(totCountOfType, totCountOfType + JmpTypeNum, 0);
  size_t totMispredictCount =
      std::accumulate(totMispredictOfType, totMispredictOfType + JmpTypeNum, 0);

  size_t totAccuracy = totBranchCount - totMispredictCount;
  os << "total branch count: " << totBranchCount << "\n";
  os << "total mispredict count: " << totMispredictCount << "\n";
  os << "total accuracy count: " << totAccuracy << "\n";
  double accuracyPerc =
      totBranchCount == 0
          ? NAN
          : ((double)totAccuracy / (double)totBranchCount) * 100.0;
  os << "accuracy: " << accuracyPerc << " %\n";
  os << "mispredict rate: " << (100.0 - accuracyPerc) << " %\n";

  Table t;
  t.add_row({"Type", "Total\nCount", "Mispredict\nCount", "Accuracy\n%",
             "Count %\n(in tot)", "Mispredict %\n(in tot)"});
  for (int i = 0; i < JmpTypeNum; i++) {
    double accPerc =
        totCountOfType[i] == 0
            ? NAN
            : ((double)(totCountOfType[i] - totMispredictOfType[i]) /
               (double)totCountOfType[i]) *
                  100.0;
    double countPerc =
        totBranchCount == 0
            ? NAN
            : ((double)totCountOfType[i] / (double)totBranchCount) * 100.0;
    double mispredPerc =
        totBranchCount == 0
            ? NAN
            : ((double)totMispredictOfType[i] / (double)totBranchCount) * 100.0;
    t.add_row(RowStream{} << nameOf(i) << totCountOfType[i]
                          << totMispredictOfType[i] << accPerc << countPerc
                          << mispredPerc);
  }
  _PrintTable(t, os);
}

void AXI4CounterBase::dumpStatistics(std::ostream &os) {
  spdlog::error("AXI4CounterBase::dumpStatistics unimpled!!!");
}

static void _AddTableRowForAXI4Counter(Table &t, AXI4CounterBase &ctr) {
  double avg_latency =
      ctr.transaction_count == 0
          ? NAN
          : (double)ctr.total_latency_cycles / (double)ctr.transaction_count;
  t.add_row(RowStream{} << ctr.ctrName << ctr.transaction_count
                        << ctr.total_latency_cycles << avg_latency
                        << ctr.maxRecord.cycles << ctr.maxRecord.startTime);
}
void AXI4PerfCounterManager::dumpStatistics(std::ostream &os) {
  os << "AXI4 Performance Counters Statistics:\n";

  Table t;
  t.add_row({"Name", "Transactions", "Total\nCycles", "Avg\nLatency",
             "Max\nLatency", "Max Start\n(sim time)"});
  for (AXI4CounterBase &ctr : rdCounters) {
    _AddTableRowForAXI4Counter(t, ctr);
  }
  for (AXI4CounterBase &ctr : wrCounters) {
    _AddTableRowForAXI4Counter(t, ctr);
  }
  _PrintTable(t, os);
}
