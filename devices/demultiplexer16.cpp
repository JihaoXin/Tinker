#include "demultiplexer16.hh"

Demultiplexer16::Demultiplexer16() {
    cycles = 0.5; // using same stats as demultiplexer for now
    area = 500;
    power = 0.25;
}

Demultiplexer16::~Demultiplexer16() {}

void Demultiplexer16::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport[0] = 0;
    outport[1] = 0;
    outport[2] = 0;
    outport[3] = 0;
    outport[4] = 0;
    outport[5] = 0;
    outport[6] = 0;
    outport[7] = 0;
    outport[8] = 0;
    outport[9] = 0;
    outport[10] = 0;
    outport[11] = 0;
    outport[12] = 0;
    outport[13] = 0;
    outport[14] = 0;
    outport[15] = 0;

    outport[*ctrlport] = *inport[0];
}