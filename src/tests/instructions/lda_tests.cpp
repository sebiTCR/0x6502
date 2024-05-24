#include <gtest/gtest.h>
#include "emu/components/cpu.hpp"


CPU cpu;
RAM ram;


TEST(LDA, TestACCManipulation){
    cpu.reset(ram);
    ram[0xFFFC] = OPCODE_JSR;
    ram[0xFFFD] = 0x42;
    ram[0xFFFE] = 0x42;
    ram[0x4242] = OPCODE_LDA_IM;
    ram[0x4243] = 0x84;

    cpu.execute(9, ram);
    
    ASSERT_EQ(cpu.registers.ACC, 0x84);
}

TEST(LDA, TestACCManipulation2){
    cpu.reset(ram);
    ram[0xFFFC] = OPCODE_JSR;
    ram[0xFFFD] = 0x42;
    ram[0xFFFE] = 0x42;
    ram[0x4242] = OPCODE_LDA_IM;
    ram[0x4243] = 0x84;

    cpu.execute(9, ram);
    
    ASSERT_EQ(cpu.registers.ACC, 0);
}
