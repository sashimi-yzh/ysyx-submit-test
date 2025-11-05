#!/usr/bin/env python
# coding: utf-8

# In[1]:


import os
import pandas as pd
import argparse
import sys


# In[2]:


def check_table(table):
    red_color = "\033[01;31m"
    clear_color = "\033[01m"
    if(table.iloc[table.shape[0]-1,1]!="default"):
        sys.stderr.write(f"{red_color}The last row of table must be default values!{clear_color}\n")
        return False


def gen_code(table):
    table_isnull = table.isnull()
    code_list2d = []
    for col in range(table.shape[1]):
        max_len = 0;
        if(col == 0):
            continue
        for row in range(table.shape[0]):
            if(col == 0):
                continue
            elif(col == 1):
                if(col == 1 and table_isnull.iloc[row,col]):
                    print(f"{red_color}ERROR: A cell in `inst_type` column is null{clear_color}")
                    exit(1)
                code_list2d.append([table.iloc[row,col]]);

            else:
                if table_isnull.iloc[row,col]:
                    code_list2d[row].append(table.iloc[table.shape[0]-1,col])
                else:
                    code_list2d[row].append(table.iloc[row,col])

            max_len = max_len if max_len > len(str(table.iloc[row, col])) else len(str(table.iloc[row, col]))
        for row in range(table.shape[0]):
                code_list2d[row][col-1] += " " * (max_len - len(code_list2d[row][col-1]))

    #
    code = "val map = Array(\n"
    code_default = "val \n";

    def gen_one_line(code_list, isdefault):
        code = ""
        for j in range(len(code_list2d[i])):
            if(j == 0):
                code += f"\t{code_list2d[i][j]} " + (" = " if(isdefault) else "-> ") + " List("
            elif(j == len(code_list2d[i]) - 1):
                code += f"{code_list2d[i][j]})" + ("" if(isdefault) else ",")
            else:
                code += f"{code_list2d[i][j]}, "
        code += "\n"
        return code;

    for i in range(len(code_list2d)):
        if(i != len(code_list2d) - 1):
            code += gen_one_line(code_list2d[i], False)
        else:
            code_default += gen_one_line(code_list2d[i], True)

    code += ")\n"


    return code + code_default

# In[68]:

prev_code = """
/****************************************************
*
* Automatically generated file; DO NOT EDIT.
*
*****************************************************/

package  cpu


import chisel3._
import chisel3.util._
import insts._

object SigMap{


  import pc_sel._
  import A_sel._
  import B_sel._
  import imm_sel._
  import aluop._
  import wb_sel._
  import valid._
  import mask_sel._
  import st_sel._
  import ld_sel._
  import br_sel._
  import csr_cmd._
  import inst_type._

"""
end_code = "\n}\n\n"


table = pd.read_excel("control_table.xlsx")
check_table(table)
# for col in range(table.shape[1]):
#     for row in range(table.shape[0]):
#         print(f"{row},{col}: {table.iloc[row,col]}")
print(prev_code + gen_code(table) + end_code)
#print(gen_assign(table, 4))

