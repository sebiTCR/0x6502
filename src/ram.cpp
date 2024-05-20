#include "emu/components/ram.hpp"

RAM::RAM(){

}


void RAM::write_word (u32 cycles, Word data_t, u32 addr){
    data[addr]     = data_t & 0xFF;
    data[addr + 1] = ( data_t >> 8);
    cycles -= 2;
}


void RAM::reset(){
    for(u32 i = 0; i < MAX_MEM; i++ )
        data[i] = 0x0;
}
