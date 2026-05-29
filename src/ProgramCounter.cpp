#include "ProgramCounter.hpp"

void ProgramCounter::set(uint32_t value){
    pc = value;
}
void ProgramCounter::increment(){
    pc++;
}
uint32_t get() const{
    return pc;
}