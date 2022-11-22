#include "add4.hh"
Add4::Add4() {
    cycles = 1;
    area = 100;
    power = 0.1;
}

Add4::~Add4() {}

void Add4::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = *inport[0] + 4;
}