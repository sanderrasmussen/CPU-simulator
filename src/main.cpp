#include "CPU.hpp"

int main() {
    CPU cpu;

    cpu.loadProgram("testProgram.txt");  
    cpu.run();                            
    return 0;
}