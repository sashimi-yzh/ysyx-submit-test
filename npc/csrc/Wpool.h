#pragma once
#include <cstdlib>
#include <stdint.h>
#include <list>
#include <string.h>
#include <stdio.h>
#include "Expr.h"
#define NR_WP 32
typedef struct watchpoint
{
	char regex[512];
	uint32_t value_before;
} WP;
class Wpool
{
public:
	void print_wp()
	{
		printf("watchpoint list:\n");
		for (auto it = wp_list.begin(); it != wp_list.end(); ++it)
		{

			printf("id %ld regex %s val oct:%010u hex:0x%08x\n", wp_list.size(), it->regex, it->value_before, it->value_before);
		}
	}
	void add_wp(char *regex, Expr &expr)
	{
		// printf("add_wp %s\n", regex);
		WP wp;
		strcpy(wp.regex, regex);
		bool success;
		wp.value_before = expr.expr(regex, &success);
		if (!success)
		{
			printf("error: %s\n", regex);
			return;
		}
		wp_list.push_back(wp);
	}
	bool check_wp(Expr &expr)
	{
		bool flag = false;
		for (auto it = wp_list.begin(); it != wp_list.end(); ++it)
		{
			bool success;
			uint32_t newval = expr.expr(it->regex, &success);
			if (newval != it->value_before)
			{
				printf("update:id %ld regex %s preval oct:%010u hex:0x%08x newval oct:%010u hex:0x%08x\n", wp_list.size(), it->regex, it->value_before, it->value_before, newval, newval);
				it->value_before = newval;
				flag = true;
			}
		}
		return flag;
	}
	void free_wp_id(int id)
	{
		auto it = wp_list.begin();
		for (int i = 0; i < id; i++)
		{
			if (it == wp_list.end())
				return;
			it++;
		}
		if (it != wp_list.end())
			wp_list.erase(it);
	}

private:
	std::list<WP> wp_list;
};
