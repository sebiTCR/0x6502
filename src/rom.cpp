#include "emu/components/rom.hpp"
#include "emu/types.hpp"
#include <fstream>
#include <spdlog/spdlog.h>

ROM::ROM(){}
ROM::~ROM(){}


void ROM::parse_file(std::string filename_t){
    std::ifstream romfile(filename_t, std::ios::binary); 
    int i = 0;
    char byte;

    spdlog::info("Reading rom file...");
    while(!romfile.eof()){
        romfile.get(byte);
        m_data.push_back((Byte) byte);
    }
}



void ROM::load_rom(RAM &ram){
    for(int i = 0; i < m_data.size(); i++){
        ram.data[0xFFFA + i] = m_data[i];
    }
}