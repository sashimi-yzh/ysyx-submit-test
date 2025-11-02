#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <stdint.h>
#include "VysyxSoCFull.h"


#define NO_REG 16

extern "C" void get_current_reg(int32_t id, int32_t regvalue);

void update_reg(VysyxSoCFull* top);
void display_reg();
int32_t str2val_reg(const char *s, bool *success);

#endif

