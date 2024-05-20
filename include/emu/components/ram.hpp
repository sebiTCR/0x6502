#pragma once
#include "emu/types.hpp"

class RAM{
public:
    RAM();
    ~RAM() = default;

    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte data[MAX_MEM];

    Byte operator[] ( u32 addr) const  { return data[addr]; }
    Byte& operator[]( u32 addr)        { return data[addr]; }

    void reset();
    void write_word (u32 cycles, Word data_t, u32 addr);
};