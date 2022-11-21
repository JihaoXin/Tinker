#ifndef TYPES_HH
#define TYPES_HH

#include <cstdint>

typedef double Port;
typedef double Reg;

struct instruction_t {
  uint32_t opcode:5;
  uint32_t register_d:5;
  uint32_t register_s:5;
  uint32_t register_t:5;
  uint32_t literal:12;
};

#endif