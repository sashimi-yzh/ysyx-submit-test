#!/usr/bin/env python
# coding: utf-8

# In[1]:


import sys


# In[49]:


instpats = []

with open("tmp.c","r") as f:
    lines = f.readlines()
    for line in lines:
        line = line.strip().split("//")[0].rstrip()
        if(not line):
            continue
        instpats.append(line)


# In[50]:


class Inst:
    def __init__(self, pat="", name="", type_="", exe=""):
        self.pat = pat
        self.name = name
        self.type_ = type_
        self.exe = exe
    
    def __str__(self):
        return (f"pat: {self.pat}\n"
                f"name: {self.name}\n"
                f"type: {self.type_}\n"
                f"ext: {self.exe}\n")  


# In[51]:


insts = []
for instpat in instpats:
    inst_raw = instpat.split(",")
    pat = inst_raw[0].strip().split("\"")[1]  
    name = inst_raw[1].strip()
    type_ = inst_raw[2].strip()
    exe = ",".join(inst_raw[3:]).strip()[0:-2]
    inst = Inst(pat=pat, name=name, type_=type_, exe=exe)
    insts.append(inst)


# In[52]:


for inst in insts:
    print(f"exe_{inst.name:<6}:",end="")
    exe = ""
    if(inst.type_ =="I" or inst.type_ == "R" or inst.type_ == "B" or inst.type_ =="S"):
        exe += "src1 = R(icache[index].rs1); "
    if(inst.type_ == "S" or inst.type_ == "R" or inst.type_ == "B"):
        exe += "src2 = R(icache[index].rs2); "
    if(inst.type_ =="I" or inst.type_ =="U" or inst.type_ =="S" or inst.type_ =="J" or 
        inst.type_ =="B"):
        exe += "imm = icache[index].imm;"
    exe += "rd = icache[index].rd; "
    exe += inst.exe
    
    print(f"  {exe}; goto __instpat_end_;")


# In[ ]:





# In[ ]:




