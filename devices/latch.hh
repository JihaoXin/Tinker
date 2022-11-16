#ifndef LATCH_HH
#define LATCH_HH
#include "device.hh"
#include <array>


class Latch {
public:
    long long value; // long long so latch is agnostic to whatever type is used. 
};

#endif
