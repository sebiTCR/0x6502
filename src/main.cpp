#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <spdlog/spdlog.h>
#include "emu/components/cpu.hpp"
#include "emu/components/ram.hpp"
#include "emu/components/instructions/instructions.hpp"
#include "emu/components/rom.hpp"
#include "emu/graphics/window.hpp"
#include "emu/types.hpp"


int main(){
    Window window;
    RAM mem;
    CPU cpu;
    ROM rom;


    cpu.reset( mem );
    window.display(cpu, mem, rom);


    return 0;
}