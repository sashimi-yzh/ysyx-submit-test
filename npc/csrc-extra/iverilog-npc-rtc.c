#include <sys/time.h>
#include <stdint.h>
#include <vpi_user.h>

static uint64_t boot_time;
static int has_init;

static uint64_t get_time(void) {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return (uint64_t)tv.tv_sec * 1000000ULL + (uint64_t)tv.tv_usec;
}

static PLI_INT32 time_init(PLI_BYTE8 *user_data) {
  (void)user_data;
  if (!has_init) {
    boot_time = get_time();
    has_init = 1;
  }
  return 0;
}

static PLI_INT32 get_timel_since_boot(PLI_BYTE8 *user_data) {
  (void)user_data;
  vpiHandle call_handle = vpi_handle(vpiSysTfCall, 0);
  s_vpi_value value = {0};
  value.format = vpiIntVal;
  value.value.integer = (PLI_INT32)(get_time() - boot_time);
  vpi_put_value(call_handle, &value, 0, vpiNoDelay);
  return 0;
}

static PLI_INT32 get_timeh_since_boot(PLI_BYTE8 *user_data) {
  (void)user_data;
  vpiHandle call_handle = vpi_handle(vpiSysTfCall, 0);
  s_vpi_value value = {0};
  value.format = vpiIntVal;
  value.value.integer = (PLI_INT32)((get_time() - boot_time) >> 32);
  vpi_put_value(call_handle, &value, 0, vpiNoDelay);
  return 0;
}

static void timel_register(void) {
  s_vpi_systf_data tf_data = {0};

  tf_data.type = vpiSysFunc;
  tf_data.sysfunctype = vpiSysFuncInt;
  tf_data.tfname = "$timel";
  tf_data.calltf = get_timel_since_boot;
  tf_data.compiletf = time_init;
  tf_data.sizetf = 0;
  vpi_register_systf(&tf_data);
}

static void timeh_register(void) {
  s_vpi_systf_data tf_data = {0};

  tf_data.type = vpiSysFunc;
  tf_data.sysfunctype = vpiSysFuncInt;
  tf_data.tfname = "$timeh";
  tf_data.calltf = get_timeh_since_boot;
  tf_data.compiletf = time_init;
  tf_data.sizetf = 0;
  vpi_register_systf(&tf_data);
}

void (*vlog_startup_routines[])(void) = {timel_register, timeh_register, 0};
