#include "emu/components/cpu.hpp"

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

            case OPCODE_JSR: {
                instructions->run_jsr(this, mem, cycles);
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