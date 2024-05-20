#include <stdio.h>
#include <stdlib.h>
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"
#include "emu/components/instructions/instructions.hpp"


int main(){
    RAM mem;
    CPU cpu;

    cpu.reset( mem );
    // mem[0xFFFC] = OPCODE_JSR;
    // mem[0xFFFD] = 0x42;
    // mem[0x0042] = 0x84;



    cpu.execute(2, mem);

    return 0;
}