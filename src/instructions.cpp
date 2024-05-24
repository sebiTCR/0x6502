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
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_zpx(CPU* cpu, RAM &ram, u32 cycles){
    Byte ZPAddr = cpu->fetch(cycles, ram);
    ZPAddr += cpu->registers.X;
    cycles--;
    cpu->registers.ACC = cpu->gfetch(cycles, ZPAddr, ram);

    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_zp(CPU* cpu, RAM &ram, u32 cycles){
    Byte ZPAddr        = cpu->fetch(cycles, ram);
    cpu->registers.ACC = cpu->gfetch(cycles, ZPAddr, ram);
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}

//TBC
void Instructions::run_lda_abs(CPU* cpu, RAM &ram, u32 cycles){
    Word addr_abs = cpu->fetch(cycles, ram);
    cpu->registers.ACC = cpu->gfetch(cycles, addr_abs, ram);
}


//TBI
void Instructions::run_jmp(CPU* cpu, RAM &ram, u32 cycles){

}


void Instructions::run_inx(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X++;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
    cycles -= 2;
}


void Instructions::run_iny(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.Y++;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
    cycles -= 2;
}


void Instructions::run_clc(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.C   = 0;
    cycles -= 2;
}


void Instructions::run_cld(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.D   = 0;
    cycles -= 2;
}


void Instructions::run_cli(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.I   = 0;
    cycles -= 2;
}


void Instructions::run_clv(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.V   = 0;
    cycles -= 2;
}
