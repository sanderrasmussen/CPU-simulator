#include "CPU.hpp"
#include <iostream>
#include <fstream>
#include "Parser.hpp"

void CPU::loadProgram(std::string programFilePath){
    std::ifstream programFile("program.txt");
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(programFile, line)){
        lines.push_back(line);
    }
    CPU::programMemory = parser.ParseProgram(lines);
}
void CPU::excecute(const Instruction &instruction){

    switch (instruction.opcode) {
        case Opcode::MOV:
        CPU::executeMov(instruction);
        break;

        case Opcode::ADD:
        CPU::executeAdd(instruction);
        break;
        
        case Opcode::SUB:
        CPU::executeSub(instruction);
        break;

        case Opcode::PRINT:
        CPU::executePrint(instruction);
        break;
    }
        

}
void CPU::executeMov(const Instruction& instruction){
    RegisterType arg1 = CPU::parseRegister(instruction.arg1);
    uint16_t value ;
    //if arg2 not register
    if (instruction.arg2[0] != 'R'){
        uint16_t value = static_cast<uint16_t>(std::stoi(instruction.arg2));
    }
    else {
        //if arg2 is register e.g. R2
        RegisterType reg = parseRegister(instruction.arg2);
        value = registers.get(reg);
    }
    CPU::registers.set(arg1, value);
}
void CPU::executeAdd(const Instruction& instruction){

}
void CPU::executeSub(const Instruction& instruction){

}
void CPU::executePrint(const Instruction& instruction){
    //get value in arg1 and print value
    RegisterType reg = CPU::parseRegister(instruction.arg1);
    std::cout << registers.get(reg) << std::endl;
}

RegisterType CPU::parseRegister(const std::string& reg) {
    if (reg.size() != 2 || reg[0] != 'R') {
        throw std::runtime_error("Invalid register: " + reg);
    }

    int index = reg[1] - '0';

    if (index < 0 || index >= Registers::COUNT) {
        throw std::runtime_error("Register out of range: " + reg);
    }

    return static_cast<RegisterType>(index);
}
void CPU::run(){
    running = true;
    pc.set(0);

    while (running){
        Instruction instruction = programMemory[pc.get()];
        excecute(instruction);
        pc.increment();
    }
    
}