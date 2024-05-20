#pragma once
#include "emu/components/cpu.hpp"
#include "emu/types.hpp"

/**
 * @brief Loads a byte of memory into the accumulator setting the zero and negative flags as appropriate.
 * 
 */

namespace Instructions
{
    void run_lda_im(CPU cpu, RAM &ram, u32 cycles){
        Byte value = cpu.fetch(cycles, ram);
        cpu.registers.ACC = value;
        cpu.registers.Z = SET_ZERO_FLAG;
        cpu.registers.N = SET_NEGATIVE_FLAG;
    }
} 
