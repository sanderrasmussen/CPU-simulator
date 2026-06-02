#pragma once 

#include <vector>
#include "instruction.hpp"
#include "Registers.hpp"
#include "programCounter.hpp"

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

        void excecute(const Instruction& instruction);
        void executeMov(const Instruction& instruction);
        void executeAdd(const Instruction& instruction);
        void executeSub(const Instruction& instruction);
        void executePrint(const Instruction& instruction);
        RegisterType parseRegister(const std::string& reg);
};