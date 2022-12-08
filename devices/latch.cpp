#include "latch.hh"
Latch::Latch() {
    inport = NULL;
    ctrlport = NULL;
    outport = 0;
}

Latch::~Latch() {}

void Latch::receive_clock() {
    if (inport != NULL && ctrlport != NULL && *ctrlport == 1) {
        outport = *inport;

    }
}

void Latch::connect(outport_t *p_outport) {
    inport = p_outport;
}

void Latch::connect_signal(outport_t *p_outport) {
    ctrlport = p_outport;
}