#pragma once
#include <stdint.h>

using Byte = uint8_t;
using Word = uint16_t;
using u32 = unsigned int;

enum ADDR_MODE{
    AM_IM,
    AM_ABS,
    AM_ABX,
    AM_ABY,
    AM_IND,
    AM_INX,
    AM_INY,
    AM_ZP0,
    AM_ZPX,
    AM_ZPY
};