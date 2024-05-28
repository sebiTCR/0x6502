#include "emu/components/cpu.hpp"
#include <spdlog/spdlog.h>

CPU::CPU(){
    instructions = new Instructions();
}


void CPU::reset(RAM& ram){
    pointers.PC = 0xFFFC;
    pointers.SP = 0x01;

    registers.ACC = 0x0;
    registers.D   = 0x0;
    registers.C   = 0x0;
    registers.Z   = 0x0;
    registers.I   = 0x0;
    registers.D   = 0x0;
    registers.B   = 0x0;
    registers.V   = 0x0; 
    registers.N   = 0x0;
    registers.X   = 0x0; 
    registers.Y   = 0x0;

    ram.reset();
}

void CPU::execute(u32 cycles, RAM& mem){
    for(u32 i = 0; i < cycles; i++){
        Byte ins = fetch(cycles, mem);
        switch (ins){
            case OPCODE_LDA_IM: {
                instructions->run_lda_im(this, mem, cycles);
                break;
            }

            case OPCODE_LDA_ZP:{
                instructions->run_lda_zp(this, mem, cycles);
                break;
            }

            case OPCODE_LDA_ZPX:{
                instructions->run_lda_zpx(this, mem, cycles);
                break;
            }

            case OPCODE_LDA_ABS:{
                instructions->run_lda_abs(this, mem, cycles);
                break;    
            }

            case OPCODE_LDA_ABX:{
                instructions->run_lda_abx(this, mem, cycles);
                break;    
            }

            case OPCODE_LDA_ABY:{
                instructions->run_lda_aby(this, mem, cycles); 
                break;   
            }

            case OPCODE_LDA_INX:{
                instructions->run_lda_inx(this, mem, cycles);
                break;    
            }

            case OPCODE_LDA_INY:{
                instructions->run_lda_iny(this, mem, cycles); 
                break;   
            }

            case OPCODE_LDX_IM:{
                instructions->run_ldx_im(this, mem, cycles); 
                break;   
            }

            case OPCODE_LDX_ZP:{
                instructions->run_ldx_zp(this, mem, cycles);  
                break;  
            }

            case OPCODE_LDX_ZPY:{
                instructions->run_ldx_zpy(this, mem, cycles);  
                break;  
            }

            case OPCODE_LDX_ABS:{
                instructions->run_ldx_abs(this, mem, cycles);
                break;   
            }

            case OPCODE_LDX_ABY:{
                instructions->run_ldx_aby(this, mem, cycles); 
                break;   
            }

            case OPCODE_LDY_IM:{
                instructions->run_ldy_im(this, mem, cycles);   
                break; 
            }

            case OPCODE_LDY_ZP:{
                instructions->run_ldy_zp(this, mem, cycles); 
                break;   
            }

            case OPCODE_LDY_ZPX:{
                instructions->run_ldy_zpx(this, mem, cycles);  
                break;  
            }

            case OPCODE_LDY_ABS:{
                instructions->run_ldy_abs(this, mem, cycles);   
                break; 
            }

            case OPCODE_LDY_ABX:{
                instructions->run_ldy_abx(this, mem, cycles); 
                break;   
            }

            case OPCODE_STX_ABS:
                instructions->run_stx(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_STX_ZP:
                instructions->run_stx(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_STX_ZPY:
                instructions->run_stx(ADDR_MODE::AM_ZPY, this, mem, cycles);
                break;

            case OPCODE_STY_ABS:
                instructions->run_sty(ADDR_MODE::AM_ABS, this, mem, cycles);

            case OPCODE_STY_ZP:
                instructions->run_sty(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_STY_ZPX:
                instructions->run_sty(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_INX:{
                instructions->run_inx(this, mem, cycles);
                break;
            }

            case OPCODE_INY:{
                instructions->run_iny(this, mem, cycles);
                break;
            }

            case OPCODE_DEX:{
                instructions->run_dex(this, mem, cycles);
                break;
            }

            case OPCODE_DEY:{
                instructions->run_dey(this, mem, cycles);
                break;
            }

            case OPCODE_JSR: {
                instructions->run_jsr(this, mem, cycles);
                break;
            }

            case OPCODE_CLC: {
                instructions->run_clc(this, mem, cycles);
                break;
            }

            case OPCODE_CLD: {
                instructions->run_cld(this, mem, cycles);
                break;
            }

            case OPCODE_CLI: {
                instructions->run_cli(this, mem, cycles);
                break;
            }

            case OPCODE_CLV: {
                instructions->run_clv(this, mem, cycles);
                break;
            }

            default:{
                if(ins == 0)
                    break;
                printf("Illegal opcode: %08x\n", ins);
                break;
            }
        }
    }
}


//Ghost fetching without affecting the PC
Byte CPU::gfetch(u32 cycles, Byte address, RAM& mem){
    Byte data = mem[address];
    cycles--;
    return data;
}


Word CPU::gfetch(u32 cycles, Word address, RAM& mem){
    Word data = mem[address];
    cycles--;
    return data;
}


Byte CPU::fetch(u32 cycles, RAM& mem){
    Byte data = mem[pointers.PC];
    pointers.PC++;
    cycles--;
    return data;
}


Word CPU::wfetch(u32 cycles, RAM& mem){
    Word data = mem[pointers.PC];
    pointers.PC++;
    cycles--;

    data |= ( mem[pointers.PC] << 8);
    pointers.PC++;
    cycles+=2;
    return data;
}