#include "Parser.hpp"
#include <stdexcept>
#include <sstream>

Parser::Parser(){

}

std::vector<Instruction> Parser::ParseProgram(std::vector<std::string> &lines){
    std::vector<Instruction> program;

    //loop lines and add instructions

    for (auto &line : lines){
        std::istringstream stream(line);
        std::string op, arg1, arg2;

        stream >> op >> arg1 >> arg2;

        // Remove trailing commas from arguments
        if (!arg1.empty() && arg1.back() == ',') {
            arg1.pop_back();
        }
        if (!arg2.empty() && arg2.back() == ',') {
            arg2.pop_back();
        }

        Instruction instruction;
        instruction.opcode = this->toOpcode(op);
        instruction.arg1 = arg1;
        instruction.arg2 = arg2;
        program.push_back(instruction);

    }
    return program;

}
Opcode Parser::toOpcode(const std::string &op) {
    if (op == "MOV") return Opcode::MOV;
    if (op == "ADD") return Opcode::ADD;
    if (op == "SUB") return Opcode::SUB;
    if (op == "PRINT") return Opcode::PRINT;
    if (op == "HALT") return Opcode::HALT;
    if (op == "JMP") return Opcode::JMP;
    if (op == "CMP") return Opcode::CMP;
    if (op == "JZ") return Opcode::JZ;
    if (op == "LOAD") return Opcode::LOAD;
    if (op == "STORE") return Opcode::STORE;

    throw std::runtime_error("Unknown opcode: " + op);
}