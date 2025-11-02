#include <sys/time.h>
#include <memory/memory.h>


uint32_t timer_addr[2] = {0, 0};
extern bool difftest_to_skip;
extern bool difftest_skipping;

static uint64_t boot_time = 0;


static uint64_t get_time_internal(){
	struct timeval now;
	gettimeofday(&now, NULL);
	uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
	return us;
}



uint64_t get_time(){
	if(boot_time == 0)
		boot_time = get_time_internal();
	uint64_t now = get_time_internal();
	return now - boot_time;
}



int fetch_timer_addr(uint32_t raddr){
	difftest_skipping = true;
    if(raddr == RTC_ADDR){
        timer_addr[0] = (uint32_t)get_time();
		return timer_addr[0];
    }
    else if(raddr == RTC_ADDR + 4){
        timer_addr[1] = (uint32_t)(get_time() >> 32);
		return timer_addr[1];
    }
	return 0;
}




