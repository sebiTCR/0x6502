#include <stdio.h>
#include <stdlib.h>

// #define Byte unsigned char; //Replace with uint8
// #define Word unsigned short;
using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Memory{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte data[MAX_MEM];

    void init(){
        for(u32 i = 0; i < MAX_MEM; i++ )
            data[i] = 0x0;
    }

    void write_word (u32 cycles, Word data_t, u32 addr){
        data[addr]     = data_t & 0xFF;
        data[addr + 1] = ( data_t >> 8);
        cycles -= 2;

    }

    Byte operator[] ( u32 addr) const { return data[addr]; }
    Byte& operator[]( u32 addr)        { return data[addr]; }

};


struct CPU {


    Word PC;
    Word SP;

    Byte ACC;
    Byte X, Y;

    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

    void reset(Memory& mem){
        PC = 0xFFFC;
        D  = 0x0;
        SP = 0x01;
        ACC = 0x0;
        C = Z= I = D = B = V = N = X = Y = 0x0;

        mem.init();
    }

    void execute(u32 cycles, Memory& mem){
        for(size_t i = 0; i < cycles; i++){
            Byte ins = fetch(cycles, mem);
            switch (ins){
                case INS_LDA_IM: {
                    Byte value = fetch(cycles, mem);
                    ACC = value;
                    Z = (ACC == 0);
                    N = (ACC & 0b10000000) > 0;
                    break;
                }

                case INS_LDA_ZP:{
                    Byte ZPAddr = fetch(cycles, mem);
                    ACC = gfetch(cycles, ZPAddr, mem);
                    Z = (ACC == 0);
                    N = (ACC & 0b10000000) > 0;
                    break;
                }

                case INS_LDA_ZPX:{
                    Byte ZPAddr = fetch(cycles, mem);
                    ZPAddr += X;
                    cycles--;
                    ACC = gfetch(cycles, ZPAddr, mem);


                    Z = (ACC == 0);
                    N = (ACC & 0b10000000) > 0;
                    break;
                }

                case INS_JSR: {
                    Word sr_addr = wfetch(cycles, mem);
                    mem.write_word( PC - 1, SP, cycles);

                    cycles--;
                    PC = sr_addr;
                    cycles--;
                    break;
                }
            }

        }
    }


    //Ghost fetching without affecting the PC
    Byte gfetch(u32 cycles, Byte address, Memory& mem){
        Byte data = mem[address];
        cycles--;
        return data;
    }


    Byte fetch(u32 cycles, Memory& mem){
        Byte data = mem[PC];

        PC++;
        cycles--;
        return data;
    }


    Word wfetch(u32 cycles, Memory& mem){
        Word data = mem[PC];
        PC++;
        cycles--;

        data |= ( mem[PC] << 8);
        PC++;
        cycles+=2;
        return data;
    }


    static constexpr Byte INS_LDA_IM  = 0xA9;
    static constexpr Byte INS_LDA_ZP  = 0xA5;
    static constexpr Byte INS_LDA_ZPX = 0xB5;
    static constexpr Byte INS_JSR     = 0x20;



};

int main(){
    Memory mem;
    CPU cpu;

    cpu.reset( mem );
    mem[0xFFFC] = CPU::INS_LDA_ZP;
    mem[0xFFFD] = 0x42;
    mem[0x0042] = 0x84;



    cpu.execute(2, mem);

    return 0;
}