#pragma once
#include "emu/types.hpp"
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"

static Byte current_working_address = 0x0;

static constexpr Byte OPCODE_LDA_IM  = 0xA9;
static constexpr Byte OPCODE_LDA_ZP  = 0xA5;
static constexpr Byte OPCODE_LDA_ZPX = 0xB5;
static constexpr Byte OPCODE_JSR     = 0x20;
static constexpr Byte OPCODE_JMP_ABS = 0x4C;
static constexpr Byte OPCODE_JMP_IND = 0x6C;
static constexpr Byte OPCODE_INX     = 0xE8;
static constexpr Byte OPCODE_INY     = 0xC8;
static constexpr Byte OPCODE_DEX     = 0xCA;
static constexpr Byte OPCODE_DEY     = 0x88; 
static constexpr Byte OPCODE_CLC     = 0x18;
static constexpr Byte OPCODE_CLD     = 0xD8;
static constexpr Byte OPCODE_CLI     = 0x58;
static constexpr Byte OPCODE_CLV     = 0xB8;


class CPU; // Dummy

class Instructions{
public:
    void run_jsr     (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_im  (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_zpx (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_zp  (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_abs (CPU* cpu, RAM &ram, u32 cycles);

    void run_jmp     (CPU* cpu, RAM &ram, u32 cycles);

    void run_inx     (CPU* cpu, RAM &ram, u32 cycles);
    void run_iny     (CPU* cpu, RAM &ram, u32 cycles);

    void run_dex     (CPU* cpu, RAM &ram, u32 cycles);
    void run_dey     (CPU* cpu, RAM &ram, u32 cycles);

    void run_clc     (CPU* cpu, RAM &ram, u32 cycles);
    void run_cld     (CPU* cpu, RAM &ram, u32 cycles);
    void run_cli     (CPU* cpu, RAM &ram, u32 cycles);
    void run_clv     (CPU* cpu, RAM &ram, u32 cycles);



};