#include "emu/components/instructions/adressing_modes.hpp"
#include "emu/components/ram.hpp"


Word ABS(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte lo = cpu_t->fetch(cycles_t, ram_t);
    Byte hi = cpu_t->fetch(cycles_t, ram_t);
    Word addr = (hi << 8) | lo;

    return addr;
}


Byte ZP0(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte addr = cpu_t->fetch(cycles_t, ram_t);
    cpu_t->registers.ACC = cpu_t->gfetch(cycles_t, addr, ram_t);

    addr &= 0x00FF;
    return addr;
}


Byte ZPX(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte addr = cpu_t->fetch(cycles_t, ram_t);
    addr += cpu_t->registers.X;

    return addr;
}


Byte ZPY(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte addr = cpu_t->fetch(cycles_t, ram_t);
    addr += cpu_t->registers.X;

    return addr;
}


Word ABX(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Word addr = ABS(cpu_t, ram_t, cycles_t);
    addr += cpu_t->registers.X;
    
    return addr;
}


Word ABY(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Word addr = ABS(cpu_t, ram_t, cycles_t);
    addr += cpu_t->registers.Y;
    
    return addr;
}


Word IND(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte lo = cpu_t->fetch(cycles_t, ram_t);
    Byte hi = cpu_t->fetch(cycles_t, ram_t);
    Word addr = (lo << 8) | hi;
    Word abs_addr;

    // Simulated HW Bug
    if(lo == 0x00FF){
        abs_addr = (
            cpu_t->gfetch(cycles_t, (Word)(addr & 0xFF00), ram_t) << 8 |
            cpu_t->gfetch(cycles_t, (Word)(addr + 1), ram_t));
    } else {
        abs_addr = (
            (cpu_t->gfetch(cycles_t, (Word)(addr + 1), ram_t) << 8) |
             cpu_t->gfetch(cycles_t, (addr), ram_t)
            );
    }

}


Word INX(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte offset = cpu_t->fetch(cycles_t, ram_t);
    Byte lo     = cpu_t->gfetch(cycles_t, (Byte)(((cpu_t->registers.X) + offset) & 0x0FF), ram_t);
    Byte hi     = cpu_t->gfetch(cycles_t, (Byte)(((cpu_t->registers.X) + offset + 1) & 0x0FF), ram_t);
    Word addr   = (hi << 8) | lo;

    return addr;
}


Word INY(CPU* cpu_t, RAM ram_t,  u32 cycles_t){
    Byte offset = cpu_t->fetch(cycles_t, ram_t);
    Byte lo     = cpu_t->gfetch(cycles_t, (Byte)(((cpu_t->registers.Y) + offset) & 0x0FF), ram_t);
    Byte hi     = cpu_t->gfetch(cycles_t, (Byte)(((cpu_t->registers.Y) + offset + 1) & 0x0FF), ram_t);
    Word addr   = (hi << 8) | lo;

    return addr;
}

