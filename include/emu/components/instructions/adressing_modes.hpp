#pragma once
#include "instructions.hpp"

Byte ABS(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute
Byte ABX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to) X
Byte ABY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Absolute (relative to Y)
Byte IND(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect
Byte INX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) X
Byte INY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Indirect (relative to) Y
Byte ZP0(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page 0
Byte ZPX(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) X
Byte ZPY(CPU* cpu_t, RAM ram_t,  u32 cycles_t); // Zero Page (relative to) Y