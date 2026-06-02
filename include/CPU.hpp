#pragma once 

#include <vector>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ProgramCounter.hpp"
#include "Parser.hpp"

class CPU{
    public:
        CPU();
        void loadProgram(std::string programFilePath);
        void run();

    private:
        std::vector<Instruction> programMemory;
        Registers registers;
        ProgramCounter pc;
        Parser parser;
        bool running;
        bool zeroFlag;

        uint16_t getRegisterValue(const std::string& regString);
        void execute(const Instruction& instruction);
        void executeMov(const Instruction& instruction);
        void executeAdd(const Instruction& instruction);
        void executeSub(const Instruction& instruction);
        void executePrint(const Instruction& instruction);
        void executeJmp(const Instruction& instruction);
        void executeJz(const Instruction& instruction); 
        void executeCmp(const Instruction& instruction); 
        RegisterType parseRegister(const std::string& reg);
};