#include <gdb.h>
#include <isa.h>
#include <common.h>
#include <cpu/cpu.h>
#include <memory/vaddr.h>
#include <stdio.h>
#include <utils.h>
#include <fmt-def.h>
#include <errno.h>
#include <memory/paddr.h>
#include <breakpoint.h>

bool gdbstub_valid = false;

void execute(uint64_t n);


void use_gdbstub(bool enable){
        gdbstub_valid = enable;
}

#ifndef CONFIG_SOC_DIFFTEST
//#define GDBSTUB_LOG

void print_nemu_state(){
#ifdef GDBSTUB_LOG
        printf(nemu_state.state == NEMU_RUNNING ? ":-- STATE: running" 
                : nemu_state.state == NEMU_END ? ":-- STATE: end"
                : nemu_state.state == NEMU_ABORT ? ":-- STATE: abort"
                : nemu_state.state == NEMU_QUIT  ? ":-- STATE: quit"
                : nemu_state.state == NEMU_STOP  ? ":-- STATE: stop"
                                                 : ":-- STATE: other");
        putchar('\n');
#endif 
}

static int nemu_read_reg(void *args, int regno, size_t *value)
{
#ifdef GDBSTUB_LOG
        printf(":---read_reg: %d\n", regno);
#endif 
        // if (regno > 32 || regno < 0)
        // {
        //         printf(":---ERROR: read_reg: %d\n", regno);
        //         return -1;
        // }
        if (regno < 32){
                *value = (size_t)isa_reg_read(regno);
                return 0;
        }
        switch (regno){
                case 32 : *value = (size_t)cpu.pc; break;
                case 33: *value = (size_t)cpu.csr.mstatus; break;
                case 34: *value = (size_t)cpu.csr.mtvec; break;
                case 35: *value = (size_t)cpu.csr.mepc; break;
                case 36: *value = (size_t)cpu.csr.mcause; break;
                default: printf(":---ERROR: read_reg: %d\n", regno); return -1;
        }

        
        return 0;
}

static int nemu_write_reg(void *args, int regno, size_t data)
{
#ifdef GDBSTUB_LOG
        printf(":---write_reg: %d %zx\n", regno, data);
#endif
        isa_reg_write(regno, data);
        return 0;
}

static int nemu_read_mem(void *args, size_t addr, size_t len, void *val)
{
#ifdef GDBSTUB_LOG
        printf(":---read_mem = " FMT_WORD_HEX " %zx\n", (word_t)addr, len);
#endif
        if (addr + len > CONFIG_MSIZE + CONFIG_MBASE)
        {
                printf(":---ERROR: read_mem = " FMT_WORD_HEX " %zx\n", (word_t)addr, len);
                return EFAULT;
        }
        else if (in_pmem(addr))
        {
                memcpy(val, get_pmem_addr() + (addr - CONFIG_MBASE), len);
        }
        else
        {
                memcpy(val, get_pmem_addr() + addr, len);
        }

        return 0;

}

static int nemu_write_mem(void *args, size_t addr, size_t len, void *val)
{
#ifdef GDBSTUB_LOG
        printf(":---write_mem = " FMT_WORD_HEX " %zx %x\n", (word_t)addr, len, *(uint32_t *)val);
#endif 

        if (addr + len > CONFIG_MSIZE + CONFIG_MBASE)
        {
                printf(":---ERROR: read_mem = " FMT_WORD_HEX " %zx\n", (word_t)addr, len);
                return EFAULT;
        }
        else if (in_pmem(addr))
        {
                memcpy(get_pmem_addr() + (addr - CONFIG_MBASE), val, len);
        }
        else
        {
                memcpy(get_pmem_addr() + addr, val, len);
        }
        return 0;
}

gdb_action_t nemu_cont(void *args)
{
        nemu_state.state = NEMU_RUNNING;
        cpu_exec(-1);
        print_nemu_state();
#ifdef GDBSTUB_LOG
        printf(":---continue over\n");
#endif
        return ACT_RESUME;
}

static gdb_action_t nemu_stepi(void *args)
{
#ifdef GDBSTUB_LOG
        printf(":---stepi\n");
#endif 
        print_nemu_state();
        if (nemu_state.state == NEMU_RUNNING || nemu_state.state == NEMU_STOP){
                nemu_state.state = NEMU_RUNNING;
                execute(1);
        }
        return ACT_RESUME;
}

static bool nemu_set_bp(void *args, size_t addr, bp_type_t type)
{
#ifdef GDBSTUB_LOG
        printf(":---set breakpoints = %x %zx %x\n", type, addr, type);
#endif
        if (type == BP_SOFTWARE)
                return add_breakpoint(addr);
        else
                return false;
}

static bool nemu_del_bp(void *args, size_t addr, bp_type_t type)
{
#ifdef GDBSTUB_LOG
        printf(":---remove breakpoints = %x %zx %x\n", type, addr, type);
#endif 
        if (type == BP_SOFTWARE)
                return del_breakpoint(addr);
        else
                return false;
}

static void nemu_on_interrupt(void *args)
{
#ifdef GDBSTUB_LOG
        printf(":---interrupt\n");
#endif 
        (void)args;
        nemu_state.state = NEMU_END;
}

struct target_ops nemu_ops = {
    .read_reg = nemu_read_reg,
    .write_reg = nemu_write_reg,
    .read_mem = nemu_read_mem,
    .write_mem = nemu_write_mem,
    .cont = nemu_cont,
    .stepi = nemu_stepi,
    .set_bp = nemu_set_bp,
    .del_bp = nemu_del_bp,
    .on_interrupt = nemu_on_interrupt,
};

void print_target_ops(const struct target_ops *ops)
{
        printf("Function pointers: \n");
        printf("  Read Register: %p\n", (void *)ops->read_reg);
        printf("  Write Register: %p\n", (void *)ops->write_reg);
        printf("  Read Memory: %p\n", (void *)ops->read_mem);
        printf("  Write Memory: %p\n", (void *)ops->write_mem);
        printf("  Continue: %p\n", (void *)ops->cont);
        printf("  Single Step: %p\n", (void *)ops->stepi);
        printf("  Set Breakpoint: %p\n", (void *)ops->set_bp);
        printf("  Delete Breakpoint: %p\n", (void *)ops->del_bp);
        printf("  On Interrupt: %p\n", (void *)ops->on_interrupt);
}

void print_arch_info(const arch_info_t *arch)
{
        printf("Arch info: \n");
        printf("  Description: %s\n", arch->target_desc);
        printf("  Number of registers: %d\n", arch->reg_num);
        printf("  Register size (bytes): %zu\n", arch->reg_byte);
}

void print_gdbstub(const gdbstub_t *gdbstub)
{
        printf("GDB Stub Information:\n");
        print_target_ops(gdbstub->ops);
        print_arch_info(&gdbstub->arch);
        // print_gdbstub_private(gdbstub->priv);
}

bool init_gdbstub()
{       
        
        Log("GDB Stub: %s", gdbstub_valid? ANSI_FMT("ON", ANSI_FG_GREEN): ANSI_FMT("OFF", ANSI_FG_RED));

        if(!gdbstub_valid)
                return true;
        
        char ip_port[32];
        sprintf(ip_port, "%s", "127.0.0.1:9012");

        
        printf("Waiting for GDB connection on %s...\n", ip_port);

        arch_info_t arch = {
            .reg_byte = 4,
            .reg_num = MUXDEF(CONFIG_RVE,16,32) + 1 , // PC and csr
            .target_desc = MUXDEF(CONFIG_RV64, TARGET_RV64, MUXDEF(CONFIG_RVE,"riscv:rv32e",TARGET_RV32)),
        };

        

        if (!gdbstub_init(&gdbstub, &nemu_ops, arch, ip_port))
        {
                fprintf(stderr, "Fail to create socket.\n");
                return false;
        }

        print_gdbstub(&gdbstub);

        if (!gdbstub_run(&gdbstub, NULL))
        {
                fprintf(stderr, "Fail to run in debug mode.\n");
                return false;
        }

        return true;
}

#else  
bool init_gdbstub(){return true;}
#endif 