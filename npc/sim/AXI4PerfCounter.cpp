#include "PerfCounter.hpp"

void AXI4CounterBase::init_logger() {
  // assert(!name.empty());
  logger = spdlog::stdout_color_mt(ctrName);
  set_logger_pattern_with_simtime(logger);
  logger->set_level(spdlog::level::info);
}



void AXI4ReadPerfCounter::update() {
  auto sim_time = sim_get_time();
  switch (state) {
  case IDLE: {
    if (hARValid.get()){
      state = WAIT_DATA;
      transaction_count++;
      currentRecord.startTime = sim_time;
      currentRecord.cycles = 0;
      // logger->trace("ARVALID high, starting transaction {}", transaction_count);
    }
    break;
  }
  case WAIT_DATA: {
    currentRecord.cycles++;
    if (hRValid.get() == 1 && hRReady.get() == 1) {
      // handshake happened
      currentRecord.endTime = sim_time;
      total_latency_cycles += currentRecord.cycles;
      if (currentRecord.cycles > maxRecord.cycles) {
        maxRecord = currentRecord;
      }
      // logger->trace(
      //     "RVALID & RREADY handshake for transaction {} after {} cycles",
      //     transaction_count, currentRecord.cycles);
      state = IDLE;
    }
    break;
  }
  }
}
void AXI4WritePerfCounter::update() {
  auto sim_time = sim_get_time();
  switch (state) {
  case IDLE: {
    if (hAWValid.get() == 1) {
      state = WAIT_RESP;
      transaction_count++;
      currentRecord.startTime = sim_time;
      currentRecord.cycles = 0;
      // logger->trace("AWVALID high, starting transaction {}", transaction_count);
    }
    break;
  }
  case WAIT_RESP: {
    currentRecord.cycles++;
    if (hBValid.get() == 1 && hBReady.get() == 1) {
      // handshake happened
      currentRecord.endTime = sim_time;
      total_latency_cycles += currentRecord.cycles;
      if (currentRecord.cycles > maxRecord.cycles) {
        maxRecord = currentRecord;
      }
      // logger->trace(
      //     "BVALID & BREADY handshake for transaction {} after {} cycles",
      //     transaction_count, currentRecord.cycles);
      state = IDLE;
    }
    break;
  }
  }
}

void AXI4PerfCounterManager::update() {
  for (auto &ctr : rdCounters) {
    ctr.update();
  }
  for (auto &ctr : wrCounters) {
    ctr.update();
  }
}

