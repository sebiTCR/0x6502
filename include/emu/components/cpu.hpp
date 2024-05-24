#pragma once

#define SET_ACC_NEGATIVE_FLAG   (cpu->registers.ACC & 0b10000000) > 0;
#define SET_ACC_ZERO_FLAG       (cpu->registers.ACC == 0);

#define SET_X_NEGATIVE_FLAG     (cpu->registers.X & 0b10000000) > 0;
#define SET_X_ZERO_FLAG              (cpu->registers.X == 0);

#define SET_Y_NEGATIVE_FLAG     (cpu->registers.Y & 0b10000000) > 0;
#define SET_Y_ZERO_FLAG              (cpu->registers.Y == 0);



#include "emu/components/ram.hpp"
#include "emu/types.hpp"
#include "emu/components/instructions/instructions.hpp"


typedef struct{
    Word PC;
    Word SP;
} Pointers;

typedef struct{
    Byte ACC;
    Byte X, Y;

    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

} Registers;


class Instructions;

class CPU {
public:
    CPU();
    ~CPU() = default;

    Pointers pointers;
    Registers registers;
    Instructions* instructions;


    /**
     * @brief Reset CPU to the initial state
     * 
     * @param ram Computer's RAM
     */
    void reset(RAM& ram);


    /**
     * @brief Execute opcode
     * 
     * @param cycles Cycles to do
     * @param ram Computer's RAM
     */
    void execute(u32 cycles, RAM& ram);


    /**
     * @brief Ghost Fetching - Fetch a byte from the RAM without altering the Program Counter
     * 
     * @param cycles Cycles to do
     * @param address Address from where to fetch the data
     * @param ram Computer's RAM
     * @return Byte Fetched data
     */
    Byte gfetch(u32 cycles, Byte address, RAM& ram);


    /**
     * @brief Ghost Fetching - Fetch a Word from the RAM without altering the Program Counter
     * 
     * @param cycles Cycles to do
     * @param address Address from where to fetch the data
     * @param ram Computer's RAM
     * @return Byte Fetched data
     */
    Word gfetch(u32 cycles, Word address, RAM& ram);


    /**
     * @brief Fetches one byte from the memory
     * 
     * @param cycles Cycles to do
     * @param ram Computer's RAM
     * @return Byte Fetched byte from memory
     */
    Byte fetch(u32 cycles, RAM& ram);


    /**
     * @brief Fetches word from the RAM
     * 
     * @param cycles Cycles to do
     * @param ram Computer's RAM
     * @return Word Fetched word from the memory
     */
    Word wfetch(u32 cycles, RAM& ram);
};
