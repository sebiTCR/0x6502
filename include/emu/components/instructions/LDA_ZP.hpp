#pragma once
#include "emu/components/cpu.hpp"
#include "emu/types.hpp"

namespace Instructions
{
    void run_lda_zp(CPU cpu, RAM &ram, u32 cycles){
        Byte ZPAddr       = cpu.fetch(cycles, ram);
        cpu.registers.ACC = cpu.gfetch(cycles, ZPAddr, ram);
        cpu.registers.Z   = SET_ZERO_FLAG;
        cpu.registers.N   = SET_NEGATIVE_FLAG;
    } 
} 
