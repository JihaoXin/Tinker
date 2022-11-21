#ifndef TYPES_HH
#define TYPES_HH

#include <cstdint>

typedef long long *Port;
typedef long long Reg;

struct instruction_t {
  uint32_t opcode:5;
  uint32_t register_d:5;
  uint32_t register_s:5;
  uint32_t register_t:5;
  uint32_t literal:12;
};

#endif