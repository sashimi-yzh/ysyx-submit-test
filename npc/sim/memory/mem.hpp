#pragma once

#include <cstdint>
#include <cstddef>

#include "../sim.hpp"

#include "mregion.hpp"

#include "socmem.hpp"

// impl by currently using SoC
mem_region_group_t& get_mem_regions();

struct mem_region_data_span {
	std::string_view name;
	uint32_t host_base;
	size_t size;
	void* data;
};
using mem_region_data_span_vec = std::vector<mem_region_data_span>;

mem_region_data_span_vec get_mem_regions_need_init_difftest();

void init_mem(void* img, const sim_config& cfg);

uint8_t* mem_guest_to_host(uint32_t addr);
bool read_guest_mem(uint32_t addr, uint32_t *data);
bool write_guest_mem(uint32_t addr, uint32_t data);

