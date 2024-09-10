#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"
#include <spdlog/spdlog.h>

CPU::CPU(){
    instructions = new Instructions();
}


void CPU::reset(RAM& ram){
    pointers.PC = 0x0FFFC;
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
                break;

            case OPCODE_STY_ZP:
                instructions->run_sty(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_STY_ZPX:
                instructions->run_sty(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_AND_IM:
                instructions->run_and(ADDR_MODE::AM_IM, this, mem, cycles);
                break;
    
            case OPCODE_AND_ZP:
                instructions->run_and(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_AND_ZPX:
                instructions->run_and(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_AND_ABS:
                instructions->run_and(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_AND_ABX:
                instructions->run_and(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_AND_ABY:
                instructions->run_and(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;

            case OPCODE_AND_INX:
                instructions->run_and(ADDR_MODE::AM_INX, this, mem, cycles);
                break;

            case OPCODE_AND_INY:
                instructions->run_and(ADDR_MODE::AM_INY, this, mem, cycles);
                break;

            case OPCODE_EOR_IM:
                instructions->run_eor(ADDR_MODE::AM_IM, this, mem, cycles);
                break;
            case OPCODE_EOR_ZP:
                instructions->run_eor(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;
            case OPCODE_EOR_ZPX:
                instructions->run_eor(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;
            case OPCODE_EOR_ABS:
                instructions->run_eor(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;
            case OPCODE_EOR_ABX:
                instructions->run_eor(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;
            case OPCODE_EOR_ABY:
                instructions->run_eor(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;
            case OPCODE_EOR_INX:
                instructions->run_eor(ADDR_MODE::AM_INX, this, mem, cycles);
                break;
            case OPCODE_EOR_INY:
                instructions->run_eor(ADDR_MODE::AM_INY, this, mem, cycles);
                break;

            case OPCODE_ORA_IM:
                instructions->run_ora(ADDR_MODE::AM_IM, this, mem, cycles);
                break; 

            case OPCODE_ORA_ZP:
                instructions->run_ora(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break; 

            case OPCODE_ORA_ZPX:
                instructions->run_ora(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_ORA_ABS:
                instructions->run_ora(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_ORA_ABX:
                instructions->run_ora(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_ORA_ABY:
                instructions->run_ora(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;

            case OPCODE_ORA_INX:
                instructions->run_ora(ADDR_MODE::AM_INX, this, mem, cycles);
                break;

            case OPCODE_ORA_INY:
                instructions->run_ora(ADDR_MODE::AM_INY, this, mem, cycles);
                break;                

            case OPCODE_BIT_ZP:
                instructions->run_bit(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;
            case OPCODE_BIT_ABS:
                instructions->run_bit(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_ADC_IM:
                instructions->run_adc(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_ADC_ZP:
                instructions->run_adc(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_ADC_ZPX:
                instructions->run_adc(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_ADC_ABS:
                instructions->run_adc(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_ADC_ABX:
                instructions->run_adc(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_ADC_ABY:
                instructions->run_adc(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;

            case OPCODE_ADC_INX:
                instructions->run_adc(ADDR_MODE::AM_INX, this, mem, cycles);
                break;

            case OPCODE_ADC_INY:
                instructions->run_adc(ADDR_MODE::AM_INY, this, mem, cycles);
                break;

            case OPCODE_SBC_IM:
                instructions->run_sbc(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_SBC_ZP:
                instructions->run_sbc(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_SBC_ZPX:
                instructions->run_sbc(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_SBC_ABS:
                instructions->run_sbc(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_SBC_ABX:
                instructions->run_sbc(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_SBC_ABY:
                instructions->run_sbc(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;

            case OPCODE_SBC_INX:
                instructions->run_sbc(ADDR_MODE::AM_INX, this, mem, cycles);
                break;

            case OPCODE_SBC_INY:
                instructions->run_sbc(ADDR_MODE::AM_INY, this, mem, cycles);
                break;

            case OPCODE_CMP_IM:
                instructions->run_cmp(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_CMP_ZP:
                instructions->run_cmp(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_CMP_ZPX:
                instructions->run_cmp(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_CMP_ABS:
                instructions->run_cmp(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_CMP_ABX:
                instructions->run_cmp(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_CMP_ABY:
                instructions->run_cmp(ADDR_MODE::AM_ABY, this, mem, cycles);
                break;

            case OPCODE_CMP_INX:
                instructions->run_cmp(ADDR_MODE::AM_INX, this, mem, cycles);
                break;

            case OPCODE_CMP_INY:
                instructions->run_cmp(ADDR_MODE::AM_INY, this, mem, cycles);
                break;

            case OPCODE_CPX_IM:
                instructions->run_cpx(ADDR_MODE::AM_IM, this, mem, cycles);
                break;           
            
            case OPCODE_CPX_ZP:
                instructions->run_cpx(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;
            
            case OPCODE_CPX_ABS:
                instructions->run_cpx(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_CPY_IM:
                instructions->run_cpy(ADDR_MODE::AM_IM, this, mem, cycles);
                break;           
            
            case OPCODE_CPY_ZP:
                instructions->run_cpy(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;
            
            case OPCODE_CPY_ABS:
                instructions->run_cpy(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_JMP_ABS:
                instructions->run_jmp(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_JMP_IN:
                instructions->run_jmp(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_ROR:
                instructions->run_ror(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_ROR_ZP0:
                instructions->run_ror(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;
                
            case OPCODE_ROR_ZPX:
                instructions->run_ror(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;
                
            case OPCODE_ROR_ABS:
                instructions->run_ror(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;
                
            case OPCODE_ROR_ABX:
                instructions->run_ror(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_ROL:
                instructions->run_rol(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_ROL_ZP0:
                instructions->run_rol(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_ROL_ZPX:
                instructions->run_rol(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_ROL_ABS:
                instructions->run_rol(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_ROL_ABX:
                instructions->run_rol(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            
            case OPCODE_LSR:
                instructions->run_lsr(ADDR_MODE::AM_IM, this, mem, cycles);
                break;

            case OPCODE_LSR_ZP0:
                instructions->run_lsr(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_LSR_ZPX:
                instructions->run_lsr(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_LSR_ABS:
                instructions->run_lsr(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_LSR_ABX:
                instructions->run_lsr(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;

            case OPCODE_ASL:
                instructions->run_asl(ADDR_MODE::AM_IM, this, mem, cycles);
                break;
            
            case OPCODE_ASL_ZP0:
                instructions->run_asl(ADDR_MODE::AM_ZP0, this, mem, cycles);
                break;

            case OPCODE_ASL_ZPX:
                instructions->run_asl(ADDR_MODE::AM_ZPX, this, mem, cycles);
                break;

            case OPCODE_ASL_ABS:
                instructions->run_asl(ADDR_MODE::AM_ABS, this, mem, cycles);
                break;

            case OPCODE_ASL_ABX:
                instructions->run_asl(ADDR_MODE::AM_ABX, this, mem, cycles);
                break;


            case OPCODE_JSR_ABS:
                instructions->run_jsr(this, mem, cycles);
                break;

            case OPCODE_RTS_IM:
                instructions->run_rts(this, mem, cycles);
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

            case OPCODE_TAX:
                instructions->run_tax(this, mem, cycles);
                break;
            case OPCODE_TAY:
                instructions->run_tay(this, mem, cycles);
                break;
            case OPCODE_TSX:
                instructions->run_tsx(this, mem, cycles);
                break;
            case OPCODE_TXA:
                instructions->run_txa(this, mem, cycles);
                break;
            case OPCODE_TXS:
                instructions->run_txs(this, mem, cycles);
                break;    
            case OPCODE_TYA:
                instructions->run_tya(this, mem, cycles);
                break;            

            case OPCODE_PHA:
                instructions->run_pha(this, mem, cycles);
                break;
            case OPCODE_PHP:
                instructions->run_php(this, mem, cycles);
                break;
            case OPCODE_PLA:
                instructions->run_pla(this, mem, cycles);
                break;
            case OPCODE_PLP:
                instructions->run_plp(this, mem, cycles);
                break;

            case OPCODE_BCC:
                instructions->run_bcc(this, mem, cycles);
                break;

            case OPCODE_BCS:
                instructions->run_bcs(this, mem, cycles);
                break;

            case OPCODE_BEQ:
                instructions->run_beq(this, mem, cycles);
                break;

            case OPCODE_BMI:
                instructions->run_bmi(this, mem, cycles);
                break;

            case OPCODE_BNE:
                instructions->run_bne(this, mem, cycles);
                break;

            case OPCODE_BPL:
                instructions->run_bpl(this, mem, cycles);
                break;

            case OPCODE_BVC:
                instructions->run_bvc(this, mem, cycles);
                break;

            case OPCODE_BVS:
                instructions->run_bvs(this, mem, cycles);
                break;
                
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
    Word hi   = mem[pointers.PC + 1];
    data = (data << 8) | hi;
    cycles -= 2;
    return data;
}


void CPU::set_pc(Word value_t){
    if(value_t > RAM::MAX_MEM){
        spdlog::error("set_pc: PC Value is greater than MAX_MEM!");
        return;
    }
    pointers.PC = value_t;
}