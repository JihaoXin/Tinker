#ifndef LATCH_HH
#define LATCH_HH
#include <array>


class Latch {
public:
    Latch();
    char *value; // long long so latch is agnostic to whatever type is used. 
};

#endif
