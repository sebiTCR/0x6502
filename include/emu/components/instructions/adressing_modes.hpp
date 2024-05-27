#pragma once
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"


Word ABS(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute
Word ABX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to) X
Word ABY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to Y)
Word IND(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect
Word INX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) X
Word INY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) Y
Byte ZP0(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page 0
Byte ZPX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) X
Byte ZPY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) Y

Byte get_addressing_byte(ADDR_MODE adressing_mode_t, CPU* cpu_t, RAM ram_t,  u32 cycles_t);
Word get_addressing_word(ADDR_MODE adressing_mode_t, CPU* cpu_t, RAM ram_t,  u32 cycles_t);