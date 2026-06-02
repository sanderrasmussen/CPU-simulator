#pragma once
#include <vector>
#include "Instruction.hpp"

class Parser{
    public:
        Parser();
        std::vector<Instruction> ParseProgram(std::vector<std::string> &lines);
    private:
        Opcode toOpcode(const std::string &op);
};