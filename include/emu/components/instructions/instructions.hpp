#pragma once
#include "emu/types.hpp"
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"

// #include "LDA_IM.hpp"
// #include "LDA_ZP.hpp"
// #include "LDA_ZPX.hpp"
// #include "JSR.hpp"

static constexpr Byte OPCODE_LDA_IM  = 0xA9;
static constexpr Byte OPCODE_LDA_ZP  = 0xA5;
static constexpr Byte OPCODE_LDA_ZPX = 0xB5;
static constexpr Byte OPCODE_JSR     = 0x20;

namespace Instructions{
    void run_jsr     (CPU cpu, RAM &ram, u32 cycles);
    void run_lda_im  (CPU cpu, RAM &ram, u32 cycles);
    void run_lda_zpx (CPU cpu, RAM &ram, u32 cycles);
    void run_lda_zp  (CPU cpu, RAM &ram, u32 cycles);
}