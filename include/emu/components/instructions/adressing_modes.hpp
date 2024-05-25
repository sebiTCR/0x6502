#pragma once
#include "instructions.hpp"

Word ABS(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute
Word ABX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to) X
Word ABY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to Y)
Word IND(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect
Word INX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) X
Word INY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) Y
Byte ZP0(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page 0
Byte ZPX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) X
Byte ZPY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) Y