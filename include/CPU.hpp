#pragma once 

#include <vector>
#include "instruction.hpp"
#include "register.hpp"
#include "programCounter.hpp"

class CPU{
    public:
        CPU();
        loadProgram();
        run();

    private:
        std::vector<Instruction> program;

        Registers registers;
        ProgramCounter pc;

        bool running;
        void excecute(const Instruction& instruction);
};