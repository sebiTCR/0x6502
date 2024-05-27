#include "emu/components/ram.hpp"

RAM::RAM(){
    for(int i = 0; i < MAX_MEM; i++){
        data[i] = 0x0;
    }
}


void RAM::write_word (u32 cycles_t, Word data_t, u32 addr){
    data[addr]     = data_t & 0xFF;
    data[addr + 1] = ( data_t >> 8);
    cycles_t -= 2;
}

void RAM::write_byte (u32 cycles_t, Byte data_t, u32 addr){
    data[addr]     = data_t & 0xFF;
    cycles_t -= 2;
}



void RAM::reset(){
    for(u32 i = 0; i < MAX_MEM; i++ )
        data[i] = 0x0;
}
