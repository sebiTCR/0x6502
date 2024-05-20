#pragma once
#include "emu/components/cpu.hpp"
#include "emu/types.hpp"

namespace Instructions
{
    void run_jsr(CPU cpu, RAM &ram, u32 cycles){
        Word sr_addr = cpu.wfetch(cycles, ram);
        ram.write_word( cpu.pointers.PC - 1, cpu.pointers.SP, cycles);

        cycles--;
        cpu.pointers.PC = sr_addr;
        cycles--;
    }
} 
