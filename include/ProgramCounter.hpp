
#pragma once

#include <cstdint>

Class ProgramCounter()
{
    public:
        void set(uint32_t value);
        void increment();
        uint32_t get() const;
    
    private:
    uint32_t pc = 0;
};