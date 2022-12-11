#ifndef LATCH_HH
#define LATCH_HH
#include "types.hh"

// Latch has 1 inport and 1 outport
class Latch {
public:
    Latch();
    ~Latch();
    void receive_clock();
    void connect(outport_t *p_outport);
    void connect_signal(outport_t p_outport);
    inport_t inport;  // long long *
    outport_t outport; // long long
    long long ctrlport;
};

#endif
