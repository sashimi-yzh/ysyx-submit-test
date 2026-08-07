#pragma once
#include <bits/stdc++.h>
#include <memory.hpp>
#include <mtrace.hpp>

class AXI {
public:
  struct AXIBundle {
    // AW
    const uint32_t &awaddr;
    const uint8_t &awvalid;
    uint8_t &awready;
    const uint8_t &awid;
    const uint8_t &awlen;
    const uint8_t &awsize;
    const uint8_t &awburst;
    // W
    const uint32_t &wdata;
    const uint8_t &wstrb;
    const uint8_t &wvalid;
    uint8_t &wready;
    const uint8_t &wlast;
    // B
    uint8_t &bvalid;
    const uint8_t &bready;
    uint8_t &bresp;
    uint8_t &bid;
    // AR
    const uint32_t &araddr;
    const uint8_t &arvalid;
    uint8_t &arready;
    const uint8_t &arid;
    const uint8_t &arlen;
    const uint8_t &arsize;
    const uint8_t &arburst;
    // R
    uint32_t &rdata;
    uint8_t &rvalid;
    const uint8_t &rready;
    uint8_t &rresp;
    uint8_t &rlast;
    uint8_t &rid;
  };

private:
  AXIBundle *bundle;
  enum ReadState { ar, r };
  enum WriteState { aw, b };
  ReadState readState;
  WriteState writeState;
  // burst tracking
  uint8_t arlen;
  uint8_t rBeatCount;
  uint32_t rBurstAddr;
  AXI() {
    readState = ar;
    writeState = aw;
    bundle = nullptr;
    arlen = 0;
    rBeatCount = 0;
    rBurstAddr = 0;
  }

public:
  static AXI &getInstance() {
    static AXI axi;
    return axi;
  }
  void bind(AXIBundle *bundle) { this->bundle = bundle; }
  void eval() {
    bundle->arready = readState == ReadState::ar;
    bundle->rvalid = readState == ReadState::r;
    switch (readState) {
    case ReadState::ar: {
      bundle->rresp = 0;
      bundle->rlast = 0;
      if (bundle->arvalid) {
        rBurstAddr = bundle->araddr;
        arlen = bundle->arlen;
        rBeatCount = 0;
        readState = ReadState::r;
      }
      break;
    }
    case ReadState::r: {
      bundle->rresp = 0;
      bundle->rdata = Memory::getInstance().read(
          ((rBurstAddr + rBeatCount * 4) & ~0x3u) - NPC_RESET_VECTOR);
      bundle->rlast = rBeatCount == arlen;
      if (bundle->rready) {
        if (rBeatCount == arlen) {
          readState = ReadState::ar;
        } else {
          rBeatCount++;
        }
      }
      break;
    }
    }
    bundle->bvalid = writeState == WriteState::b;
    switch (writeState) {
      static bool awReady = 0;
      static bool wReady = 0;
      static uint32_t wAddr;
      static uint32_t wData;
      static uint8_t wStrb;
    case WriteState::aw: {
      bundle->awready = !awReady;
      bundle->wready = !wReady;
      if (bundle->awvalid) {
        awReady = 1;
        wAddr = bundle->awaddr;
      }
      if (bundle->wvalid) {
        wReady = 1;
        wData = bundle->wdata;
        wStrb = bundle->wstrb;
      }
      if (wReady && awReady) {
        Memory::getInstance().write((wAddr & ~0x3u) - NPC_RESET_VECTOR, wData,
                                    wStrb);
        writeState = WriteState::b;
      }
      break;
    }
    case WriteState::b: {
      bundle->bvalid = 1;
      if (bundle->bready) {
        awReady = 0;
        wReady = 0;
        writeState = WriteState::aw;
      }
      break;
    }
    }
  }
  bool awFire() { return bundle->awvalid && bundle->awready; }
  bool wFire() { return bundle->wvalid && bundle->wready; }
  bool bFire() { return bundle->bvalid && bundle->bready; }
  bool arFire() { return bundle->arvalid && bundle->arready; }
  bool rFire() { return bundle->rvalid && bundle->rready; }
};