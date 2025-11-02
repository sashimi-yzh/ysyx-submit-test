#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vysyx_23060229_top.h"

using namespace std;

#define MAX_SIM_TIME 30
int sim_time = 0;



// the binary instructions
static uint8_t memory[400] = {	0x93,0x80,0x10,0x00,//addi,R(1) += 1, R(1) = 1
								0x93,0x83,0x20,0x00,//addi,R(7) = R(1) + 2 = 3
								0x93,0x83,0xf3,0xff,//addi,R(7) = R(1) - 1 = 0
								0x03,0xaf,0x8f,0x01,//lw, R(30) = Mem(R(31) + 24) = Mem(0x80000024) = 0x15141312
								0x23,0xae,0xef,0x01,//sw, Mem(0x80000028) = R(30) = 0x15141312
								0x73,0x00,0x00,0x00,//ebreak
								0x12,0x13,0x14,0x15,//data for reading
								0x88,0x77,0x66,0x55 //data for rewriting
								};


uint32_t pmem_read(uint32_t addr, uint8_t byte){
	if(addr < 0x80000000 || addr > 0x8fffffff){
		printf("addr %#8.8x is not valid for reading\n",addr);
		return 0;
	}
	addr = addr - 0x80000000;
	if(byte == 1)
		return memory[addr] >> 7 ? (0xffffff00|memory[addr]) : (uint32_t)memory[addr];
	
	else if(byte == 2)
		return memory[addr+1] >> 7 ? (0xffff0000|(memory[addr+1]<<8)|memory[addr]) : 
									(uint32_t)((memory[addr+1]<<8)|memory[addr]);
	
	else if(byte == 4)
		return (memory[addr] | (uint32_t)memory[addr+1] << 8
				| (uint32_t)memory[addr+2] << 16 
				| (uint32_t)memory[addr+3] << 24);
	else
		return 0;
}


void pmem_write(uint32_t addr, uint8_t byte, uint32_t data){
	//printf("in pmem_write\n");
	if(addr < 0x80000000 || addr > 0x8fffffff){
		printf("addr %#8.8x is not valid for writing\n",addr);
		return;
	}
	addr = addr - 0x80000000;
	if(byte == 1)
		memory[addr] = (uint8_t)data;
	else if(byte == 2){
		memory[addr] = (uint8_t)data;
		memory[addr+1] = (uint8_t)(data >> 8);
	}
	else if(byte == 4){
		memory[addr] = (uint8_t)data;
		memory[addr+1] = (uint8_t)(data >> 8);
		memory[addr+2] = (uint8_t)(data >> 16);
		memory[addr+3] = (uint8_t)(data >> 24);
	}
}


int main(){
    //srand((int)time(0));// to generate random numbers
    Vysyx_23060229_top* top = new Vysyx_23060229_top;

    // to enable wave tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    top -> trace(m_trace, 5);
    m_trace -> open("./wavesim_file/wave.vcd");

    // simulation start
    cout << "simulation started" << endl;


	
	top -> clk = 0; top -> rst = 1;

	
	while(sim_time < MAX_SIM_TIME){
		printf("sim_time: %d\n",sim_time);
    	top -> clk = !top -> clk;
		if(sim_time == 7)
			top -> rst = 0;
		//after the posedge has come
		if(top -> clk){
			
			
			printf("at sim_time %d, pc = %#8.8x, inst = %#8.8x\n",sim_time,top -> pc, top -> inst);


			/*top -> eval();//very important and indispensable;
						  //to simulate the combinational circuit of mem-reading
			//step1: fetch instruction
			top -> inst = pmem_read(top -> pc, 4);
			printf("pc: %#8.8x  inst: %#8.8x\n", top->pc,top->inst);
			//top -> eval();

			
			top -> eval();//very important and indispensable
						  //to simulate the combinational circuit of mem-reading
			//step2: read mem
			if(top -> mem_rd_quest == 0b01)// read 1 byte from mem
				top -> data_from_mem = pmem_read(top -> src1 + top -> imm, 1);
			else if(top -> mem_rd_quest == 0b10)//read 2 bytes from mem
				top -> data_from_mem = pmem_read(top -> src1 + top -> imm, 2);
			else if(top -> mem_rd_quest == 0b11){//read 4 bytes from mem
				top -> data_from_mem = pmem_read(top -> src1 + top -> imm, 4);
				printf("data_from_mem: %#8.8x\n", top->data_from_mem);
			}

			
			//step3: write mem
			if(top -> mem_wr_quest == 0b01)//write 1 byte to mem
				pmem_write(top -> src1 + top -> imm, 1, top -> data_to_mem);
			else if(top -> mem_wr_quest == 0b10)//write 2 bytes to mem
				pmem_write(top -> src1 + top -> imm, 2, top -> data_to_mem);
			else if(top -> mem_wr_quest == 0b11){//write 4 bytes to mem
				pmem_write(top -> src1 + top -> imm, 4, top -> data_to_mem);
				printf("data_to_mem: %#8.8x\n", top->data_to_mem);
			}*/
		}

        top -> eval();
        m_trace -> dump(sim_time);
		++ sim_time;
	}
    


	m_trace -> close();
    delete top;
	
	//printf("%x\n",memory[28]);
    cout << "simulation completed" << endl;

    return 0;
}

