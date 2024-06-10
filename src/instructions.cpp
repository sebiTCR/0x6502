#include "emu/components/instructions/instructions.hpp"
#include "emu/components/instructions/adressing_modes.hpp"
#include <spdlog/spdlog.h>


void Instructions::run_jsr(CPU* cpu, RAM &ram, u32 cycles){
    Word sr_addr = cpu->wfetch(cycles, ram);
    ram.write_word( cycles, cpu->pointers.SP, cpu->pointers.PC - 1);

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
    Byte value = ZP0(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_abs(CPU* cpu, RAM &ram, u32 cycles){
    Word value = ABS(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_abx(CPU* cpu, RAM &ram, u32 cycles){
    Word value = ABX(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_aby(CPU* cpu, RAM &ram, u32 cycles){
    Word value = ABY(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_inx(CPU* cpu, RAM &ram, u32 cycles){
    Word value = INX(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_lda_iny(CPU* cpu, RAM &ram, u32 cycles){
    Word value = INY(cpu, ram, cycles);
    cpu->registers.ACC = value;
    cpu->registers.Z   = SET_ACC_ZERO_FLAG;
    cpu->registers.N   = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_ldx_im(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = cpu->fetch(cycles, ram);
    cpu->registers.X   = value;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
}


void Instructions::run_ldx_zp(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ZP0(cpu, ram, cycles);
    cpu->registers.X   = value;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
}


void Instructions::run_ldx_zpy(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ZPY(cpu, ram, cycles);
    cpu->registers.X   = value;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
}


void Instructions::run_ldx_abs(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ABS(cpu, ram, cycles);
    cpu->registers.X   = value;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
}


void Instructions::run_ldx_aby(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ABY(cpu, ram, cycles);
    cpu->registers.X   = value;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
}


void Instructions::run_ldy_im(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = cpu->fetch(cycles, ram);
    cpu->registers.Y   = value;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
}


void Instructions::run_ldy_zp(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ZP0(cpu, ram, cycles);
    cpu->registers.Y   = value;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
}


void Instructions::run_ldy_zpx(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ZPX(cpu, ram, cycles);
    cpu->registers.Y   = value;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
}


void Instructions::run_ldy_abs(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ABS(cpu, ram, cycles);
    cpu->registers.Y   = value;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
}


void Instructions::run_ldy_abx(CPU* cpu, RAM &ram, u32 cycles){
    Word value         = ABX(cpu, ram, cycles);
    cpu->registers.Y   = value;
    cpu->registers.Z   = SET_Y_ZERO_FLAG;
    cpu->registers.N   = SET_Y_NEGATIVE_FLAG;
}


void Instructions::run_sta(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte address = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    spdlog::info("Writting ACC to %i", address);
    ram.write_byte(cycles, cpu->pointers.PC - 1, address);
}


void Instructions::run_stx(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte address = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    spdlog::info("Writting X to {}", address);

    ram.write_byte(cycles, cpu->registers.X, address);
    spdlog::info("Data on address(dec: {}): {} ", address, ram.data[address]);

}


void Instructions::run_sty(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte address = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    ram.write_byte(cycles, cpu->registers.Y, address);

}


void Instructions::run_tax(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X = cpu->registers.ACC;
    cpu->registers.N = SET_X_NEGATIVE_FLAG;
    cpu->registers.Z = SET_X_ZERO_FLAG;
    cycles -= 2;
}


void Instructions::run_tay(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.Y = cpu->registers.ACC;
    cpu->registers.N = SET_Y_NEGATIVE_FLAG;
    cpu->registers.Z = SET_Y_ZERO_FLAG;
    cycles -= 2;
}


void Instructions::run_tsx(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X = cpu->gfetch(cycles, cpu->pointers.SP ,ram);
    cpu->registers.N = SET_X_NEGATIVE_FLAG;
    cpu->registers.Z = SET_X_ZERO_FLAG;
    cycles -= 2;
}


void Instructions::run_txa(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.Y = cpu->registers.X;
    cpu->registers.N = SET_Y_NEGATIVE_FLAG;
    cpu->registers.Z = SET_Y_ZERO_FLAG;
    cycles -= 2;
}


void Instructions::run_txs(CPU* cpu, RAM &ram, u32 cycles){
    ram.write_byte(cycles, cpu->registers.X, cpu->pointers.SP );
    cycles--;
}


void Instructions::run_tya(CPU* cpu, RAM &ram, u32 cycles){
    ram.write_byte(cycles, cpu->registers.Y, cpu->pointers.SP );
    cycles--;
}


void Instructions::run_pha(CPU* cpu, RAM &ram, u32 cycles){
    ram.write_byte(cpu->registers.ACC, cycles, cpu->pointers.PC);
    cpu->pointers.PC++;
    cycles -= 2;
}


void Instructions::run_php(CPU* cpu, RAM &ram, u32 cycles){
    Byte status = 0x0;
    status |= (cpu->registers.C << 1);
    status |= (cpu->registers.Z << 2);
    status |= (cpu->registers.I << 3);
    status |= (cpu->registers.D << 4);
    status |= (cpu->registers.B << 5);
    status |= (cpu->registers.V << 6);
    status |= (cpu->registers.N << 7);

    ram.write_byte(status, cycles, cpu->pointers.PC);
    cpu->pointers.PC++;
    cycles -= 2;
}


void Instructions::run_pla(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.ACC = ram[cpu->pointers.PC];
    cpu->registers.Z = SET_ACC_NEGATIVE_FLAG;
        cycles -= 4;
}


void Instructions::run_plp(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.C = ram[cpu->pointers.PC] & 0x10000000;
    cpu->registers.Z = ram[cpu->pointers.PC] & 0x01000000;
    cpu->registers.I = ram[cpu->pointers.PC] & 0x00100000;
    cpu->registers.D = ram[cpu->pointers.PC] & 0x00010000;
    cpu->registers.B = ram[cpu->pointers.PC] & 0x00001000;
    cpu->registers.V = ram[cpu->pointers.PC] & 0x00000100;
    cpu->registers.N = ram[cpu->pointers.PC] & 0x00000010;
    cycles -= 4;
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


void Instructions::run_dex(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X--;
    cpu->registers.Z   = SET_X_ZERO_FLAG;
    cpu->registers.N   = SET_X_NEGATIVE_FLAG;
    cycles -= 2;
}


void Instructions::run_dey(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.Y--;
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
