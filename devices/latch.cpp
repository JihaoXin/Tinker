#include "latch.hh"
Latch::Latch() {
    inport = NULL;
    outport = 0;
}

Latch::~Latch() {}

void Latch::receive_clock() {
    if (inport != NULL) {
        outport = *inport;
    }
}

void Latch::connect(outport_t *p_outport) {
    inport = p_outport;
}