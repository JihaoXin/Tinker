#ifndef LATCH_HH
#define LATCH_HH
#include <array>

class Latch {
public:
    Latch();
    unsigned char *value; // unsigned char so latch is agnostic to whatever type is used. 
};

#endif
