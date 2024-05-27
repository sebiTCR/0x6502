#include "emu/components/rom.hpp"
#include "emu/types.hpp"
#include <fstream>
#include <spdlog/spdlog.h>

ROM::ROM(){
    spdlog::info("Initalizing ROM.");
    for(int i = 0; i < 1024; i++)
        m_data[i] = 0x0;
    spdlog::info("Initialized ROM.");
}
ROM::~ROM(){}

void ROM::parse_file(std::string filename_t){
    std::ifstream romfile(filename_t, std::ios::binary); 
    int i = 0;
    char byte;


    spdlog::info("Reading rom file...");
    while(!romfile.eof()){
        // if(i > 6 ){
        //     break;
        // }
        romfile.get(byte);
        m_data[i] = (Byte) byte;

        printf("Reading index: %i\n", i);
        i++;
    }
}


void ROM::load_rom(RAM &ram){
    int i = 0;
    for(Byte byte : m_data){
        if(byte == 0x0)
            break;
        ram.data[0xFFFA + i] = byte;
        i++;
    }
}
