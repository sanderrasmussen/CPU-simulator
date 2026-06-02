cmake_minimum_required(VERSION 3.10)
project(CPU_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Legg til alle source-filer
add_executable(cpu_simulator
    src/main.cpp
    src/CPU.cpp
    src/Memory.cpp
    src/Registers.cpp
    src/ProgramCounter.cpp
    src/Parser.cpp
    src/Debugger.cpp
)

# Legg til include-directory
target_include_directories(cpu_simulator PRIVATE include)

# Sett output-mappe
set_target_properties(cpu_simulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
