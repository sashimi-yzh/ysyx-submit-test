#include "mem.hpp"
#include <cstdint>
#include <fstream>

#ifdef SIM_ARCH_NPC

static std::shared_ptr<direct_mapped_mem> _pmem_ptr;
// only jmp to pmem instructions
static std::shared_ptr<direct_mapped_mem> _dummy_flash_ptr;

mem_region_group_t &get_mem_regions() {
  static mem_region_group_t mem_regions;
  if (mem_regions.empty()) {
    if (_pmem_ptr && _dummy_flash_ptr) {
      mem_regions.push_back(*_pmem_ptr);
			mem_regions.push_back(*_dummy_flash_ptr);
    } else {
      spdlog::warn("try to get mem regions of npc before init, returning empty "
                   "region list");
    }
  }
  return mem_regions;
}

void init_mem(void *img, const sim_config &cfg) {
  spdlog::info("copy img to pmem of npc");

  _pmem_ptr = std::make_shared<direct_mapped_mem>(
      0x80000000u, 0xa0000000u, "pmem", 128 * 1024 * 1024,
      get_dut()
          ->TestSoC->vlSymsp->TOP__TestSoC__devices__mem__mem__mem_ext
          .Memory.data());
  _pmem_ptr->copy_from(img, cfg.img_size);

	_dummy_flash_ptr = std::make_shared<direct_mapped_mem>(
			0x30000000u, 0x40000000u, "dummy_flash", 1024,
			get_dut()
					->TestSoC->vlSymsp->TOP__TestSoC__devices__startupROM__mem__mem_ext
					.Memory.data());

	std::fstream dummy_flash_file("jmpROM/build/jmp.bin", std::ios::in | std::ios::binary);
	if (!dummy_flash_file.is_open()) {
		spdlog::error("failed to open dummy flash file jmpROM/build/jmp.bin");
	} else {
		dummy_flash_file.read((char *)_dummy_flash_ptr->data, 1024);
		size_t bytes_read = dummy_flash_file.gcount();
		spdlog::info("read {} bytes from dummy flash file", bytes_read);
		dummy_flash_file.close();
	}


  // auto pmemDataPtr = memcpy(pmemDataPtr, img, cfg.img_size);

  //   // memset the ASAN shadow memory to zero
  //   // instead at trm_init to optimise the init time
  // #define ASAN_SHADOW_MEMORY_START 0x7000000
  // #define ASAN_SHADOW_MEMORY_SIZE 0x1000000
  //
  //   auto psram_data = pmemDataPtr;
  //   memset((uint8_t *)psram_data + ASAN_SHADOW_MEMORY_START, 0,
  //          ASAN_SHADOW_MEMORY_SIZE);
  //   spdlog::info("ASAN shadow memory in psram zeroed");
}

mem_region_data_span_vec get_mem_regions_need_init_difftest(){
	// since init pc is set to 0x30000000, sdb_init only init difftest with
	// the dummy flash region, so the pmem region need to be inited by
	// tell sdb need to init by this callback explicitly
	return {mem_region_data_span{
		.name = _pmem_ptr->name,
		.host_base = _pmem_ptr->base(),
		.size = _pmem_ptr->actualSizeInBytes,
		.data = _pmem_ptr->data,
	}};
}
#endif
