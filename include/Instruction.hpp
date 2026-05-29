#include "instruction.hpp"
#pragma once

struct Instruction {
    Opcode opcode;

    std::string arg1;
    std::string arg2;
}
