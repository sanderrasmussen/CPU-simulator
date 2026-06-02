#include "CPU.hpp"
#include <iostream>
#include <fstream>
#include "Parser.hpp"

CPU::CPU(){
    running = false;
}

void CPU::loadProgram(std::string programFilePath){
    std::ifstream programFile(programFilePath);
    if (!programFile.is_open()) {
        throw std::runtime_error("Could not open file: " + programFilePath);
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(programFile, line)){
        lines.push_back(line);
    }
    CPU::programMemory = parser.ParseProgram(lines);
}
void CPU::execute(const Instruction &instruction){

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
        
        case Opcode::JMP:
        CPU::executeJmp(instruction);

        case Opcode::CMP:
        CPU::executeCmp(instruction);

        case Opcode::JZ:
        CPU::executeJz(instruction);
        
        default:
        break;
    }
        

}
uint16_t CPU::getRegisterValue(const std::string& regString){
    uint16_t value ;
    
    if (regString[0] != 'R'){
        //IF NOT REGISTER, JSUT RETURN THE VALUE
        value = static_cast<uint16_t>(std::stoi(regString));
    } 
    else {
        //if reg is a valid register e.g. R2
        RegisterType parsedRegister = parseRegister(regString);
        value = registers.get(parsedRegister);
    }
    return value;
}

void CPU::executeMov(const Instruction& instruction){
    RegisterType arg1 = CPU::parseRegister(instruction.arg1);
    uint16_t value = CPU::getRegisterValue(instruction.arg2);

    CPU::registers.set(arg1, value);
}
void CPU::executeAdd(const Instruction& instruction){
    RegisterType targetRegister = CPU::parseRegister(instruction.arg1);
    uint16_t arg1Value = CPU::getRegisterValue(instruction.arg1);
    uint16_t arg2value = CPU::getRegisterValue(instruction.arg2);

    CPU::registers.set(targetRegister, arg1Value + arg2value);
}
void CPU::executeSub(const Instruction& instruction){
    RegisterType targetRegister = CPU::parseRegister(instruction.arg1);
    uint16_t arg1Value = CPU::getRegisterValue(instruction.arg1);
    uint16_t arg2value = CPU::getRegisterValue(instruction.arg2);

    CPU::registers.set(targetRegister, arg1Value - arg2value);
}
void CPU::executePrint(const Instruction& instruction){
    //get value in arg1 and print value
    RegisterType reg = CPU::parseRegister(instruction.arg1);
    std::cout << registers.get(reg) << std::endl;
}
void CPU::executeJmp(const Instruction& instruction){
    this->pc.set(static_cast<uint32_t>(std::stoi(instruction.arg1)) - 1); //adding ekstra -1 due to the increment pc at end of each cpu loop
}
void CPU::executeJz(const Instruction& instruction){
    if (zeroFlag) this->pc.set(static_cast<uint32_t>(std::stoi(instruction.arg1)) - 1); //adding ekstra -1 due to the increment pc at end of each cpu loop
}
void CPU::executeCmp(const Instruction& instruction){
    uint16_t arg1Value = CPU::parseRegister(instruction.arg1);
    uint16_t arg2Value = CPU::parseRegister(instruction.arg2);
    if (arg1Value == arg2Value){
        this->zeroFlag = true;
    }
    else{
        this->zeroFlag = false;
    }
}
RegisterType CPU::parseRegister(const std::string& reg) {
    if (reg.size() < 2 || reg[0] != 'R') {
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
    zeroFlag = false;

    while (running){
        uint32_t currentPC = pc.get();
        if (currentPC >= programMemory.size()) {
            running = false;
            break;
        }
        Instruction instruction = programMemory[currentPC];
        if (instruction.opcode == Opcode::HALT) {
            running = false;
            break;
        }
        execute(instruction);
        pc.increment();
    }
    
}