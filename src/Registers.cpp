#include Registers.hpp

Registers::Registers(){
    for (int i = 0; i < COUNT; i++){
        register[i] = 0;
    }
}

Registers::set(int index, uint16_t value){
    if (index >= 0 && index <= COUNT){
        register[index] = value;
    }
}
Registers::get(int index){
    if (index >= 0 && index <= COUNT){
       return register[index];
    }
    return 0;
}
