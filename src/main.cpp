#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"
#include "emu/components/instructions/instructions.hpp"
#include "emu/graphics/window.hpp"
#include "emu/types.hpp"


std::vector<Byte> program = {
    OPCODE_INX,
    OPCODE_INX, 
    OPCODE_INX,
    OPCODE_INY,
};


int main(){
    Window window;
    RAM mem;
    CPU cpu;



    cpu.reset( mem );
    // mem[0xFFFC] = OPCODE_JSR;
    // mem[0xFFFD] = 0x42;
    // mem[0x0042] = 0x84;

    printf("Addr mem: %x", &mem);

    // for(Byte i = 0xFFC; i < program.size(); i++){
    //     mem[i] = program[i];
    // }

    mem[0xFFFC] = OPCODE_INX;
    mem[0xFFFD] = OPCODE_INY;
    mem[0xFFFE] = OPCODE_INX;
    mem[0xFFFF] = OPCODE_INY;

    cpu.execute(6, mem);

    window.display(cpu, mem);

    return 0;
}