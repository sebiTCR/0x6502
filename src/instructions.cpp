#include "emu/components/instructions/instructions.hpp"


void Instructions::run_jsr(CPU* cpu, RAM &ram, u32 cycles){
    Word sr_addr = cpu->wfetch(cycles, ram);
    ram.write_word( cpu->pointers.PC - 1, cpu->pointers.SP, cycles);

    cycles--;
    cpu->pointers.PC = sr_addr;
    cycles--;
}


void Instructions::run_lda_im(CPU* cpu, RAM &ram, u32 cycles){
    Byte value = cpu->fetch(cycles, ram);
    cpu->registers.ACC = value;
    cpu->registers.Z = SET_ZERO_FLAG;
    cpu->registers.N = SET_NEGATIVE_FLAG;
}


void Instructions::run_lda_zpx(CPU* cpu, RAM &ram, u32 cycles){
    Byte ZPAddr = cpu->fetch(cycles, ram);
    ZPAddr += cpu->registers.X;
    cycles--;
    cpu->registers.ACC = cpu->gfetch(cycles, ZPAddr, ram);


    cpu->registers.Z = SET_ZERO_FLAG;
    cpu->registers.N = SET_NEGATIVE_FLAG;
}


void Instructions::run_lda_zp(CPU* cpu, RAM &ram, u32 cycles){
    Byte ZPAddr       = cpu->fetch(cycles, ram);
    cpu->registers.ACC = cpu->gfetch(cycles, ZPAddr, ram);
    cpu->registers.Z   = SET_ZERO_FLAG;
    cpu->registers.N   = SET_NEGATIVE_FLAG;
}

