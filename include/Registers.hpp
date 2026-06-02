#pragma once 
#include <cstdint>

enum RegisterType {
    R0, R1, R2, R3, R4, R5, R6, R7
};

class Registers {
    public:
        static constexpr int COUNT = 8; //8 registre

        Registers();

        void set(int index, uint16_t value);
        uint16_t get(int index) const;

    private:
        uint16_t r[COUNT];
};