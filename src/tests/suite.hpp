#pragma once
#include "emu/components/cpu.hpp"

class TestContext{
public:
    TestContext();

    CPU cpu;
    RAM ram;
};