/**
 * @file rom.hpp
 * @author 
 * @brief Represents the actual ROM that will be loaded into memory. As a main responsability, the class should be able to parse a ROM file and load it into memory.
 * 
 * @copyright Copyright SebiTCR(c) 2024
 * 
 */

#pragma once
#include "emu/components/ram.hpp"
#include "emu/types.hpp"
#include <string>
#include <vector>

//TODO: FIX ROM LOADING PROCCESS.
class ROM{
public:
    ROM();
    ~ROM();

    void parse_file(std::string filename_t);
    void load_rom(RAM &ram);

private:
    Byte m_data[1024];
};

