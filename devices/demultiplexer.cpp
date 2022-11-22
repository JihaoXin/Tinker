#include "demultiplexer.hh"

Demultiplexer::Demultiplexer() {
    cycles = 0.5;
    area = 500;
    power = 0.25;
}

Demultiplexer::~Demultiplexer() {}

void Demultiplexer::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (*ctrlport == 0) {
        outport[0] = *inport[0];
        outport[1] = 0;
        outport[2] = 0;
        outport[3] = 0;
    } else if (*ctrlport == 1) {
        outport[0] = 0;
        outport[1] = *inport[0];
        outport[2] = 0;
        outport[3] = 0;
    } else if (*ctrlport == 16) {
        outport[0] = 0;
        outport[1] = 0;
        outport[2] = *inport[0];
        outport[3] = 0;
    } else if (*ctrlport == 17) {
        outport[0] = 0;
        outport[1] = 0;
        outport[2] = 0;
        outport[3] = *inport[0];
    } 
}