#include "emu/components/instructions/instructions.hpp"
#include "emu/components/instructions/adressing_modes.hpp"
#include <spdlog/spdlog.h>


void Instructions::run_jsr(CPU* cpu, RAM &ram, u32 cycles){
    Word sr_addr = cpu->wfetch(cycles, ram);

    ram.write_byte(cycles, (cpu->pointers.PC - 1) >> 8, 0x0100 | cpu->pointers.SP);
    cpu->pointers.SP--;
    ram.write_byte(cycles, (cpu->pointers.PC - 1) & 0xFF, 0x0100 | cpu->pointers.SP);
    cpu->pointers.SP--;

    cpu->pointers.PC = sr_addr;
    cycles -= 6;
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
    cpu->registers.ACC = cpu->gfetch(cycles, (Word)ZPAddr, ram);
    cycles--;

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
    Word address = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    ram.write_byte(cycles, cpu->registers.ACC, address);
}


void Instructions::run_stx(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Word address = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    ram.write_byte(cycles, cpu->registers.X, address);
}


void Instructions::run_sty(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Word address = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    ram.write_byte(cycles, cpu->registers.Y, address);
}


void Instructions::run_tax(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X = cpu->registers.ACC;
    cpu->registers.N = SET_X_NEGATIVE_FLAG;
    cpu->registers.Z = SET_X_ZERO_FLAG;
}


void Instructions::run_tay(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.Y = cpu->registers.ACC;
    cpu->registers.N = SET_Y_NEGATIVE_FLAG;
    cpu->registers.Z = SET_Y_ZERO_FLAG;
}


void Instructions::run_tsx(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.X = cpu->pointers.SP;
    cpu->registers.N = SET_X_NEGATIVE_FLAG;
    cpu->registers.Z = SET_X_ZERO_FLAG;
    cycles -= 2;
}


void Instructions::run_txa(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.ACC = cpu->registers.X;
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    cycles -= 2;
}


void Instructions::run_txs(CPU* cpu, RAM &ram, u32 cycles){
    cpu->pointers.SP = cpu->registers.X;
    cycles--;
}


void Instructions::run_tya(CPU* cpu, RAM &ram, u32 cycles){
    cpu->registers.ACC = cpu->registers.Y;
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    cycles--;
}


void Instructions::run_pha(CPU* cpu, RAM &ram, u32 cycles){
    ram.write_byte(cycles, cpu->registers.ACC, 0x0100 | cpu->pointers.SP);
    cpu->pointers.SP--;
    cycles -= 3;
}


void Instructions::run_php(CPU* cpu, RAM &ram, u32 cycles){
    Byte status = 0x30;

    if (cpu->registers.C) status |= 0b00000001;
    if (cpu->registers.Z) status |= 0b00000010;
    if (cpu->registers.I) status |= 0b00000100;
    if (cpu->registers.D) status |= 0b00001000;
    if (cpu->registers.V) status |= 0b01000000;
    if (cpu->registers.N) status |= 0b10000000;

    ram.write_byte(cycles, status, 0x0100 | cpu->pointers.SP);
    cpu->pointers.SP--;
    cycles -= 3;
}


void Instructions::run_pla(CPU* cpu, RAM &ram, u32 cycles){
    cpu->pointers.SP++;
    cpu->registers.ACC = ram[0x0100 | cpu->pointers.SP];
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_plp(CPU* cpu, RAM &ram, u32 cycles){
    cpu->pointers.SP++;
    Byte stack_byte = ram[0x0100 | cpu->pointers.SP];

    cpu->registers.C = (stack_byte & 0b00000001);
    cpu->registers.Z = (stack_byte & 0b00000010) >> 1;
    cpu->registers.I = (stack_byte & 0b00000100) >> 2;
    cpu->registers.D = (stack_byte & 0b00001000) >> 3;
    // B flag ignored on PLP
    cpu->registers.V = (stack_byte & 0b01000000) >> 6;
    cpu->registers.N = (stack_byte & 0b10000000) >> 7;
}


void Instructions::run_and(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte value = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);

    cpu->registers.ACC &= value;

    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_eor(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte value = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    cpu->registers.ACC ^= value;
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    //TODO: Add cycle
}


void Instructions::run_ora(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte value = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    cpu->registers.ACC |= value;
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    cycles -= 2;
}


void Instructions::run_bit(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte value = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    cpu->registers.Z = ((value & cpu->registers.ACC) == 0);
    cpu->registers.V = (value & 0b01000000) != 0;
    cpu->registers.N = (value & 0b10000000) != 0;
}


void Instructions::run_adc(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte data = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    Word sum = (Word)cpu->registers.ACC + (Word)data + (Word)cpu->registers.C;
    
    cpu->registers.V = ( (~((Word)cpu->registers.ACC ^ (Word)data) & ((Word)cpu->registers.ACC ^ (Word)sum)) & 0x0080 ) != 0;
    cpu->registers.ACC = (Byte)(sum & 0xFF);
    cpu->registers.C = (sum > 0xFF);
    cpu->registers.C = (sum > 0xFF);
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_sbc(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte data = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    Word sum = (Word)cpu->registers.ACC + (Word)(data ^ 0xFF) + (Word)cpu->registers.C;

    cpu->registers.V = (((Word)cpu->registers.ACC ^ (Word)sum) & ((Word)cpu->registers.ACC ^ (Word)(data ^ 0xFF)) & 0x0080) != 0;
    cpu->registers.ACC = (Byte)(sum & 0xFF);
    cpu->registers.C = (sum > 0xFF);
    cpu->registers.Z = SET_ACC_ZERO_FLAG;
    cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
}


void Instructions::run_cmp(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte data = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    Byte result = cpu->registers.ACC - data;
    cpu->registers.C = (cpu->registers.ACC >= data);
    cpu->registers.Z = (cpu->registers.ACC == data);
    cpu->registers.N = (result & 0x80) != 0;
}


void Instructions::run_cpx(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte data = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    Byte result = cpu->registers.X - data;
    cpu->registers.C = (cpu->registers.X >= data);
    cpu->registers.Z = (cpu->registers.X == data);
    cpu->registers.N = (result & 0x80) != 0;
}


void Instructions::run_cpy(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte data = get_addressing_byte(addressing_mode_t, cpu, ram, cycles);
    Byte result = cpu->registers.Y - data;
    cpu->registers.C = (cpu->registers.Y >= data);
    cpu->registers.Z = (cpu->registers.Y == data);
    cpu->registers.N = (result & 0x80) != 0;
}


void Instructions::run_jmp(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    cpu->set_pc(addr);
    cycles -= 2;
}

void Instructions::run_rts(CPU* cpu, RAM &ram, u32 cycles){
    cpu->pointers.SP++;
    Byte lo = ram[0x0100 | cpu->pointers.SP];
    cpu->pointers.SP++;
    Byte hi = ram[0x0100 | cpu->pointers.SP];
    cpu->pointers.PC = ((Word)hi << 8) | lo;
    cpu->pointers.PC++;

    cycles -= 6;
}

//TODO: Find a better way to manage cycles
void Instructions::run_inc(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    Byte value = ram[addr];
    value++;
    ram.write_byte(cycles, value, addr);

    cpu->registers.N = (value & 0x80) != 0;
    cpu->registers.Z = (value == 0);
}


void Instructions::run_dec(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
    Byte value = ram[addr];
    value--;
    ram.write_byte(cycles, value, addr);

    cpu->registers.N = (value & 0x80) != 0;
    cpu->registers.Z = (value == 0);
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


//TODO: Do one more cycle if new page
void Instructions::run_bcc(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(!cpu->registers.C){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bcs(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(cpu->registers.C){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_beq(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(cpu->registers.Z){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bmi(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(cpu->registers.N){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bne(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(!cpu->registers.Z){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bpl(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(!cpu->registers.N){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bvc(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(!cpu->registers.V){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Do one more cycle if new page
void Instructions::run_bvs(CPU* cpu, RAM &ram, u32 cycles){
    s8 offset = (s8)cpu->fetch(cycles, ram);
    if(cpu->registers.V){
        Word old_pc = cpu->pointers.PC;
        cpu->pointers.PC += offset;
        cycles -= 1;
        if((old_pc & 0xFF00) != (cpu->pointers.PC & 0xFF00)) cycles -= 1;
    }
    cycles -= 2;
}


//TODO: Add Word handling, not just bit handling
//FIXME: Fix addressing modes
//FIXME: Fix flagging
void Instructions::run_rol(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte old_carry = cpu->registers.C;
    if(addressing_mode_t == ADDR_MODE::AM_IM){
        cpu->registers.C = (cpu->registers.ACC & 0x80) != 0;
        cpu->registers.ACC = (cpu->registers.ACC << 1) | old_carry;
        cpu->registers.Z = SET_ACC_ZERO_FLAG;
        cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    } else {
        Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
        Byte value = ram[addr];
        cpu->registers.C = (value & 0x80) != 0;
        value = (value << 1) | old_carry;
        ram.write_byte(cycles, value, addr);
        cpu->registers.Z = (value == 0);
        cpu->registers.N = (value & 0x80) != 0;
    }
}


void Instructions::run_ror(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    Byte old_carry = cpu->registers.C;
    if(addressing_mode_t == ADDR_MODE::AM_IM){
        cpu->registers.C = cpu->registers.ACC & 0x01;
        cpu->registers.ACC = (cpu->registers.ACC >> 1) | (old_carry << 7);
        cpu->registers.Z = SET_ACC_ZERO_FLAG;
        cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    } else {
        Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
        Byte value = ram[addr];
        cpu->registers.C = value & 0x01;
        value = (value >> 1) | (old_carry << 7);
        ram.write_byte(cycles, value, addr);
        cpu->registers.Z = (value == 0);
        cpu->registers.N = (value & 0x80) != 0;
    }
}


void Instructions::run_lsr(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    if(addressing_mode_t == ADDR_MODE::AM_IM){
        cpu->registers.C = cpu->registers.ACC & 0x01;
        cpu->registers.ACC >>= 1;
        cpu->registers.Z = SET_ACC_ZERO_FLAG;
        cpu->registers.N = 0;
    } else {
        Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
        Byte value = ram[addr];
        cpu->registers.C = value & 0x01;
        value >>= 1;
        ram.write_byte(cycles, value, addr);
        cpu->registers.Z = (value == 0);
        cpu->registers.N = 0;
    }
}


void Instructions::run_asl(ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles){
    if(addressing_mode_t == ADDR_MODE::AM_IM){
        cpu->registers.C = (cpu->registers.ACC & 0x80) != 0;
        cpu->registers.ACC <<= 1;
        cpu->registers.Z = SET_ACC_ZERO_FLAG;
        cpu->registers.N = SET_ACC_NEGATIVE_FLAG;
    } else {
        Word addr = get_addressing_word(addressing_mode_t, cpu, ram, cycles);
        Byte value = ram[addr];
        cpu->registers.C = (value & 0x80) != 0;
        value <<= 1;
        ram.write_byte(cycles, value, addr);
        cpu->registers.Z = (value == 0);
        cpu->registers.N = (value & 0x80) != 0;
    }
}


void Instructions::run_nop(u32 cycles){
    cycles -= 2;
}