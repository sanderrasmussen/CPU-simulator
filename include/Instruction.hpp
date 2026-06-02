#include "Opcodes.hpp"
#include <string>
#pragma once

struct Instruction {
    Opcode opcode;

    std::string arg1;
    std::string arg2;
};
