#include <cstdint>
#include "Registers.hpp"

Registers::Registers(){
    for (int i = 0; i < COUNT; i++){
        r[i] = 0;
    }
}

void Registers::set(int index, uint16_t value){
    if (index >= 0 && index <= COUNT){
        r[index] = value;
    }
}
uint16_t Registers::get(int index) const{
    if (index >= 0 && index <= COUNT){
       return r[index];
    }
    return 0;
}
