#pragma once 
#include <cstdint>

class Registers {
    public:
        static constexpr COUNT = 8; //8 registre

        Registers();

        void set(int index, int uint16_t value);
        uint16_t get(index) const;

    private:
        uint16_t register[COUNT];
}