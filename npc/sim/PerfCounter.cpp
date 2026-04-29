#include "PerfCounter.hpp"
#include "sim.hpp"
#include "spdlog/fmt/bundled/format.h"
#include "spdlog/spdlog.h"
#include <fstream>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

using namespace DirectSignals;

HandShakeCounterManager::ValidReadyBus &
HandShakeCounterManager::add(SignalHandle hValid, SignalHandle hReady,
                             std::string description) {
  bus_list.emplace_back(ValidReadyBus{
      .hValid = hValid,
      .hReady = hReady,
      .description = description,
  });
  return bus_list.back();
}

bool HandShakeCounterManager::ValidReadyBus::shakeHappened() {
  return hValid.get() && hReady.get();
}

void HandShakeCounterManager::update() {
  for (auto &bus : bus_list) {
    if (bus.shakeHappened()) {
      bus.shake_count++;
      // logger->trace("Handshake happened on {} (total count {})",
      //               _DebugPath(bus.description), bus.shake_count);
    }
  }
}

void PipeStagePerfCounter::update() {
  State s;
  if (hOutReady.get()) {
    if (hOutValid.get()) {
      s = Fire;
    } else {
      s = Bubble;
    }
  } else {
    s = Backpressure;
  }
  countOfState[s]++;
}

void CachePerfCounter::bind() {
  hARValid = &GetICache()->io_cpu_arvalid;
  hARReady = &GetICache()->io_cpu_arready;
  hCacheHit = &GetICache()->cacheHit;
  hState = &GetICache()->state;

  rdMemCtr.BIND_AXI4_R_BASE(GetICache()->io_mem);
}

void CachePerfCounter::update() {
  rdMemCtr.update();
  if (hARValid.get() && hARReady.get()) {
    totalVisitCount++;
    currentHitAccessStartCycle = sim_get_cycle();
  }

  auto s = (State)hState.get();
  if (s == checkHit && hCacheHit.get()) {
    hitCount++;
    totalHitAccessCycles += sim_get_cycle() - currentHitAccessStartCycle;
  }
}

void CachePerfCounter::dumpStatistics(std::ostream &os) {
  os << "Cache Performance Counter Statistics:\n";
  os << "hit rate: " << hitCount << " / " << totalVisitCount << " = "
     << hitRate() * 100.0 << " %\n";
  os << "average hit access cycles: " << avgHitAccessCycles() << "\n";
  os << "average miss access cycles: " << avgMissPenaltyCycles() << "\n";
  os << "AMAT : " << AMAT() << "\n";
}

void RAWStallPerfCounter::update() {
  if (hIsIDUStall.get()) {
    cycIDUStall++;

    if (hIsConflictEXU.get()) {
      cycConflictEXU++;
    }
    if (hIsConflictLSU.get()) {
      cycConflictLSU++;
    }
    if (hIsConflictWBU.get()) {
      cycConflictWBU++;
    }
  }
}
void RAWStallPerfCounter::bind() {
  hIsConflictEXU = &GetIDU()->bypassMux->isConflictWithEXU;
  hIsConflictLSU = &GetIDU()->bypassMux->isConflictWithLSU;
  hIsConflictWBU = &GetIDU()->bypassMux->isConflictWithWBU;
  hIsIDUStall = &GetIDU()->bypassMux->isStall;
}
IDUFlushPerfCounter::IDUFlushReason IDUFlushPerfCounter::getCurReason() const {
  auto &exu = *GetEXU();
  IDUFlushReason reason;
  if (exu.dbgIsBranch)
    reason = IDUFlushReason::BranchTaken;
  else if (exu.dbgIsJAL)
    reason = IDUFlushReason::JAL;
  else if (exu.dbgIsJALR)
    reason = IDUFlushReason::JALR;
  else if (exu.dbgIsCSRJmp)
    reason = IDUFlushReason::Exception;
  else {
    if (exu.io_fencei)
      reason = IDUFlushReason::Fence;
    else {
      reason = IDUFlushReason::Unknown;
      spdlog::warn("Unknown flush reason at {}ps", sim_get_time());
    }
  }

  return reason;
}
void IDUFlushPerfCounter::update() {
  bool isFlushRaisingEdge = (!lastCycIsFlush && hIsFlushIDU.get());
  lastCycIsFlush = hIsFlushIDU.get();

  if (isFlushRaisingEdge) {
    lastFlushReason = getCurReason();
  }

  if (hIsFlushIDU.get()) {
    cycIDUFlush++;
    cycFlushOfReason[lastFlushReason]++;
  }
}
void IDUFlushPerfCounter::bind() { hIsFlushIDU = &GetCPU()->needFlushPipeline; }

void BranchPredPerfCounter::bind() {
  hValid = &GetEXU()->io_in_valid;
  hReady = &GetEXU()->io_in_ready;
}

int BranchPredPerfCounter::getCurJmpType() const {
  auto &exu = *GetEXU();
  if (exu.dbgIsBranch)
    return JmpType::Branch;
  else if (exu.dbgIsJAL)
    return JmpType::JAL;
  else if (exu.dbgIsJALR)
    return JmpType::JALR;
  else if (exu.dbgIsCSRJmp)
    return JmpType::Exception;

  return JmpType::JmpTypeNum;
}

void BranchPredPerfCounter::update() {
  if (hValid.get() && hReady.get()) {
    auto jmpType = getCurJmpType();
    if (jmpType >= JmpType::JmpTypeNum) {
      return;
    }
    totCountOfType[jmpType]++;
    if (GetEXU()->io_predWrong) {
      totMispredictOfType[jmpType]++;
    }
  }
}

std::vector<PerfCounterVariant> perf_counters;

void initPerfCounters() {

  HandShakeCounterManager handshakeCtr;
  // EXUPerfCounter exuCtr;
  AXI4PerfCounterManager axi4Ctr;

  PipePerfManager pipeCtr;
  RAWStallPerfCounter rawStallCtr;
  IDUFlushPerfCounter iduFlushCtr;

  CachePerfCounter cacheCtr;

  BranchPredPerfCounter branchPredCtr;

  handshakeCtr.add(&GetIFU()->io_mem_rvalid, &GetIFU()->io_mem_rready,
                   "IFU fetch inst");
  handshakeCtr.add(&GetLSU()->io_mem_rvalid, &GetLSU()->io_mem_rready,
                   "EXU load data");
  handshakeCtr.add(&GetIDU()->io_out_valid, &GetIDU()->io_out_ready,
                   "IDU decode inst");

  axi4Ctr.add(AXI4WritePerfCounter().BIND_AXI4_W_BASE(GetLSU()->io_mem),
              "lsu_mem_write");
  axi4Ctr.add(AXI4ReadPerfCounter().BIND_AXI4_R_BASE(GetLSU()->io_mem),
              "lsu_mem_read");
  axi4Ctr.add(AXI4ReadPerfCounter().BIND_AXI4_R_BASE(GetIFU()->io_mem),
              "ifu_mem_read");

  pipeCtr.add(PipeStagePerfCounter().bind(
                  &GetIFU()->io_pc_valid, &GetIFU()->io_pc_ready,
                  &GetIFU()->io_out_valid, &GetIFU()->io_out_ready),
              "IFU");
  pipeCtr.add(PipeStagePerfCounter().BIND_PIPE_STAGE_BASE(GetIDU()->io), "IDU");
  pipeCtr.add(PipeStagePerfCounter().BIND_PIPE_STAGE_BASE(GetEXU()->io),
              "EXUS1");
  pipeCtr.add(PipeStagePerfCounter().BIND_PIPE_STAGE_BASE(GetEXU()->io),
              "EXUS2");
  pipeCtr.add(PipeStagePerfCounter().BIND_PIPE_STAGE_BASE(GetLSU()->io), "LSU");

  iduFlushCtr.bind();
  cacheCtr.bind();
  rawStallCtr.bind();
  branchPredCtr.bind();

  perf_counters.push_back(std::move(handshakeCtr));
  // perf_counters.push_back(std::move(exuCtr));
  perf_counters.push_back(std::move(axi4Ctr));
  perf_counters.push_back(std::move(pipeCtr));
  perf_counters.push_back(std::move(rawStallCtr));
  perf_counters.push_back(std::move(iduFlushCtr));
  perf_counters.push_back(std::move(branchPredCtr));
  perf_counters.push_back(std::move(cacheCtr));
}

void updatePerfCounters() {
  for (auto &ctr : perf_counters) {
    std::visit([&](auto &c) { c.update(); }, ctr);
  }
}
void dumpPerfCountersStatistics(std::ostream &os) {
  auto cycle_count = sim_get_cycle();
  auto inst_count = sim_get_inst_count();

  os << "Perf Counters Report\n";
  os << "Git commit: " << _STR(GIT_COMMIT_HASH) << "\n\n";

  os << "Statistics:\n";
  os << "cycle and instruction counts:\n";
  os << "  total cycle count: " << cycle_count << "\n";
  os << "  total instruction count: " << inst_count << "\n";
  if (cycle_count == 0) {
    spdlog::warn("cycle count is 0, cannot calc IPC");
  } else {
    double ipc = (double)inst_count / (double)cycle_count;
    os << fmt::format("  IPC: {:.4f}\n", ipc);
    // fmt::println("  IPC: {:.4f}", ipc);
  }
  if (inst_count == 0) {
    spdlog::warn("no instruction executed, cannot calc CPI");
  } else {
    double cpi = (double)cycle_count / (double)inst_count;
    // fmt::println("  CPI: {:.4f}", cpi);
    os << fmt::format("  CPI: {:.4f}\n", cpi);
  }

  for (auto &ctr : perf_counters) {
    std::visit([&](auto &c) { c.dumpStatistics(os); }, ctr);
  }
}

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HandShakeCounterManager::ValidReadyBus,
                                   description, shake_count)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(HandShakeCounterManager, bus_list)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AXI4CounterBase::LatencyRecord, startTime,
                                   endTime, cycles)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AXI4CounterBase, ctrName, transaction_count,
                                   total_latency_cycles, maxRecord)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(AXI4PerfCounterManager, rdCounters,
                                   wrCounters)

void to_json(nlohmann::json &j, const PipeStagePerfCounter &c) {
  j["ctrName"] = c.ctrName;
  for (int s = 0; s < PipeStagePerfCounter::STATE_NUM; s++) {
    j["countOfState"][s] = {
        {"state", PipeStagePerfCounter::nameOfState(s)},
        {"count", c.countOfState[s]},
    };
  }
}

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(PipePerfManager, stageCtrs)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(CachePerfCounter, totalVisitCount, hitCount,
                                   totalHitAccessCycles, rdMemCtr)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(RAWStallPerfCounter, cycConflictEXU,
                                   cycConflictLSU, cycConflictWBU, cycIDUStall)

void to_json(nlohmann::json &j, const IDUFlushPerfCounter &c) {
  j["ctrName"] = c.ctrName;
  j["cycIDUFlush"] = c.cycIDUFlush;
  for (int r = 0; r < IDUFlushPerfCounter::IDUFlushReason::REASON_NUM; r++) {
    j["cycFlushOfReason"][r] = {
        {"reason", IDUFlushPerfCounter::nameOfReason(r)},
        {"count", c.cycFlushOfReason[r]},
    };
  }
}
void to_json(nlohmann::json &j, const BranchPredPerfCounter &c) {
  j["ctrName"] = c.ctrName;
  for (int t = 0; t < BranchPredPerfCounter::JmpType::JmpTypeNum; t++) {
    j["totCountOfType"][t] = {
        {"type", BranchPredPerfCounter::nameOf(t)},
        {"count", c.totCountOfType[t]},
    };
    j["totMispredictOfType"][t] = {
        {"type", BranchPredPerfCounter::nameOf(t)},
        {"count", c.totMispredictOfType[t]},
    };
  }
}

void dumpPerfCounterTo(std::ostream &os) {
  // std::string title_row;
  std::string value_row;

  nlohmann::json j;

  bool first = true;
  for (auto &ctr : perf_counters) {
    std::visit([&](auto &c) { j[c.ctrName] = c; }, ctr);
  }
  // os << "\n" << value_row;
  // os << j.dump(2);
  os << j;
}
void dumpPerfReportOnDir(const std::string &dir) {
  std::string prefix = "counters";
  std::string reportPath = dir + '/' + prefix + ".report.txt";
  std::ofstream reportFile(reportPath);
  if (!reportFile.is_open()) {
    spdlog::error("cannot open perf counter report file {}", reportPath);
    return;
  }
  dumpPerfCountersStatistics(reportFile);
  reportFile.close();
  spdlog::info("perf counter report dumped to {}", reportPath);
  std::string dataPath = dir + '/' + prefix + ".rawdata.json";
  std::ofstream dataFile(dataPath);
  if (!dataFile.is_open()) {
    spdlog::error("cannot open perf counter csv file {}", dataPath);
    return;
  }
  // dumpPerfCounterTo(std::cout);
  dumpPerfCounterTo(dataFile);
  dataFile.close();
  spdlog::info("perf counter csv dumped to {}", dataPath);
}
