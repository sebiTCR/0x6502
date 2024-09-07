#pragma once
#include "emu/types.hpp"
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"


static constexpr Byte OPCODE_LDA_IM  = 0xA9;
static constexpr Byte OPCODE_LDA_ZP  = 0xA5;
static constexpr Byte OPCODE_LDA_ZPX = 0xB5;
static constexpr Byte OPCODE_LDA_ABS = 0xAD;
static constexpr Byte OPCODE_LDA_ABX = 0xBD;
static constexpr Byte OPCODE_LDA_ABY = 0xB9;
static constexpr Byte OPCODE_LDA_INX = 0xA1;
static constexpr Byte OPCODE_LDA_INY = 0xB1;

static constexpr Byte OPCODE_LDX_IM  = 0xA2;
static constexpr Byte OPCODE_LDX_ZP  = 0xA6;
static constexpr Byte OPCODE_LDX_ZPY = 0xB6;
static constexpr Byte OPCODE_LDX_ABS = 0xAE;
static constexpr Byte OPCODE_LDX_ABY = 0xBE;

static constexpr Byte OPCODE_LDY_IM  = 0xA0;
static constexpr Byte OPCODE_LDY_ZP  = 0xA4;
static constexpr Byte OPCODE_LDY_ZPX = 0xB4;
static constexpr Byte OPCODE_LDY_ABS = 0xAC;
static constexpr Byte OPCODE_LDY_ABX = 0xBC;

static constexpr Byte OPCODE_STX_ZP  = 0x86;
static constexpr Byte OPCODE_STX_ZPY = 0x96;
static constexpr Byte OPCODE_STX_ABS = 0x8E;

static constexpr Byte OPCODE_STY_ZP  = 0x04;
static constexpr Byte OPCODE_STY_ZPX = 0x94;
static constexpr Byte OPCODE_STY_ABS = 0x8c;

static constexpr Byte OPCODE_INX     = 0xE8;
static constexpr Byte OPCODE_INY     = 0xC8;

static constexpr Byte OPCODE_DEX     = 0xCA;
static constexpr Byte OPCODE_DEY     = 0x88; 

static constexpr Byte OPCODE_CLC     = 0x18;
static constexpr Byte OPCODE_CLD     = 0xD8;
static constexpr Byte OPCODE_CLI     = 0x58;
static constexpr Byte OPCODE_CLV     = 0xB8;

static constexpr Byte OPCODE_TAX     = 0xAA;
static constexpr Byte OPCODE_TAY     = 0xA8;
static constexpr Byte OPCODE_TSX     = 0xBA;
static constexpr Byte OPCODE_TXA     = 0x8A;
static constexpr Byte OPCODE_TXS     = 0x9A;
static constexpr Byte OPCODE_TYA     = 0x98;

static constexpr Byte OPCODE_PHA     = 0x48;
static constexpr Byte OPCODE_PHP     = 0x08;
static constexpr Byte OPCODE_PLA     = 0x68;
static constexpr Byte OPCODE_PLP     = 0x28;

static constexpr Byte OPCODE_AND_IM  = 0x29;
static constexpr Byte OPCODE_AND_ZP  = 0x25;
static constexpr Byte OPCODE_AND_ZPX = 0x35;
static constexpr Byte OPCODE_AND_ABS = 0x2D;
static constexpr Byte OPCODE_AND_ABX = 0x3D;
static constexpr Byte OPCODE_AND_ABY = 0x39;
static constexpr Byte OPCODE_AND_INX = 0x21;
static constexpr Byte OPCODE_AND_INY = 0x31;

static constexpr Byte OPCODE_EOR_IM  = 0x49;
static constexpr Byte OPCODE_EOR_ZP  = 0x45;
static constexpr Byte OPCODE_EOR_ZPX = 0x55;
static constexpr Byte OPCODE_EOR_ABS = 0x4D;
static constexpr Byte OPCODE_EOR_ABX = 0x5D;
static constexpr Byte OPCODE_EOR_ABY = 0x59;
static constexpr Byte OPCODE_EOR_INX = 0x41;
static constexpr Byte OPCODE_EOR_INY = 0x51;

static constexpr Byte OPCODE_ORA_IM  = 0x09;
static constexpr Byte OPCODE_ORA_ZP  = 0x05;
static constexpr Byte OPCODE_ORA_ZPX = 0x15;
static constexpr Byte OPCODE_ORA_ABS = 0x0D;
static constexpr Byte OPCODE_ORA_ABX = 0x1D;
static constexpr Byte OPCODE_ORA_ABY = 0x19;
static constexpr Byte OPCODE_ORA_INX = 0x01;
static constexpr Byte OPCODE_ORA_INY = 0x11;

static constexpr Byte OPCODE_ADC_IM  = 0x69;
static constexpr Byte OPCODE_ADC_ZP  = 0x65;
static constexpr Byte OPCODE_ADC_ZPX = 0x75;
static constexpr Byte OPCODE_ADC_ABS = 0x6D;
static constexpr Byte OPCODE_ADC_ABX = 0x7D;
static constexpr Byte OPCODE_ADC_ABY = 0x79;
static constexpr Byte OPCODE_ADC_INX = 0x61;
static constexpr Byte OPCODE_ADC_INY = 0x71;

static constexpr Byte OPCODE_SBC_IM  = 0xE9;
static constexpr Byte OPCODE_SBC_ZP  = 0xE5;
static constexpr Byte OPCODE_SBC_ZPX = 0xF5;
static constexpr Byte OPCODE_SBC_ABS = 0xED;
static constexpr Byte OPCODE_SBC_ABX = 0xFD;
static constexpr Byte OPCODE_SBC_ABY = 0xF9;
static constexpr Byte OPCODE_SBC_INX = 0xE1;
static constexpr Byte OPCODE_SBC_INY = 0xF1;

static constexpr Byte OPCODE_CMP_IM  = 0xC9;
static constexpr Byte OPCODE_CMP_ZP  = 0xC5;
static constexpr Byte OPCODE_CMP_ZPX = 0xD5;
static constexpr Byte OPCODE_CMP_ABS = 0xCD;
static constexpr Byte OPCODE_CMP_ABX = 0xDD;
static constexpr Byte OPCODE_CMP_ABY = 0xD9;
static constexpr Byte OPCODE_CMP_INX = 0xC1;
static constexpr Byte OPCODE_CMP_INY = 0xD1;

static constexpr Byte OPCODE_CPX_IM  = 0xE0;
static constexpr Byte OPCODE_CPX_ZP  = 0xE4;
static constexpr Byte OPCODE_CPX_ABS = 0xEC;

static constexpr Byte OPCODE_CPY_IM  = 0xC0;
static constexpr Byte OPCODE_CPY_ZP  = 0xC4;
static constexpr Byte OPCODE_CPY_ABS = 0xCC;

static constexpr Byte OPCODE_JMP_ABS = 0x4C;
static constexpr Byte OPCODE_JMP_IN  = 0x6C;

static constexpr Byte OPCODE_JSR_ABS = 0x20;
static constexpr Byte OPCODE_RTS_IM  = 0x60;


static constexpr Byte OPCODE_BIT_ZP  = 0x24;
static constexpr Byte OPCODE_BIT_ABS = 0x2C;


class CPU; // Dummy

class Instructions{
public:

    //TODO: Update to comply with the new addressing convetions
    void run_lda_im  (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_zpx (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_zp  (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_abs (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_abx (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_aby (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_inx (CPU* cpu, RAM &ram, u32 cycles);
    void run_lda_iny (CPU* cpu, RAM &ram, u32 cycles);

    //TODO: Update to comply with the new addressing convetions
    void run_ldx_im  (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldx_zp  (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldx_zpy (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldx_abs (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldx_aby (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldy_im  (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldy_zp  (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldy_zpx (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldy_abs (CPU* cpu, RAM &ram, u32 cycles);
    void run_ldy_abx (CPU* cpu, RAM &ram, u32 cycles);

    // Storings
    void run_sta     (ADDR_MODE addressing_mode_t ,CPU* cpu, RAM &ram, u32 cycles);
    void run_stx     (ADDR_MODE addressing_mode_t ,CPU* cpu, RAM &ram, u32 cycles);
    void run_sty     (ADDR_MODE addressing_mode_t ,CPU* cpu, RAM &ram, u32 cycles);

    void run_and     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_eor     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_ora     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_bit     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);

    void run_adc     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_sbc     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_cmp     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_cpx     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_cpy     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);

    void run_jmp     (ADDR_MODE addressing_mode_t, CPU* cpu, RAM &ram, u32 cycles);
    void run_jsr     (CPU* cpu, RAM &ram, u32 cycles);
    void run_rts     (CPU* cpu, RAM &ram, u32 cycles);

    void run_inx     (CPU* cpu, RAM &ram, u32 cycles);
    void run_iny     (CPU* cpu, RAM &ram, u32 cycles);

    void run_dex     (CPU* cpu, RAM &ram, u32 cycles);
    void run_dey     (CPU* cpu, RAM &ram, u32 cycles);

    void run_clc     (CPU* cpu, RAM &ram, u32 cycles);
    void run_cld     (CPU* cpu, RAM &ram, u32 cycles);
    void run_cli     (CPU* cpu, RAM &ram, u32 cycles);
    void run_clv     (CPU* cpu, RAM &ram, u32 cycles);

    void run_tax     (CPU* cpu, RAM &ram, u32 cycles);
    void run_tay     (CPU* cpu, RAM &ram, u32 cycles);
    void run_tsx     (CPU* cpu, RAM &ram, u32 cycles);
    void run_txa     (CPU* cpu, RAM &ram, u32 cycles);
    void run_txs     (CPU* cpu, RAM &ram, u32 cycles);
    void run_tya     (CPU* cpu, RAM &ram, u32 cycles);

    void run_pha     (CPU* cpu, RAM &ram, u32 cycles);
    void run_php     (CPU* cpu, RAM &ram, u32 cycles);
    void run_pla     (CPU* cpu, RAM &ram, u32 cycles);
    void run_plp     (CPU* cpu, RAM &ram, u32 cycles);

};