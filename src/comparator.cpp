#include "comparator.hh"

Comparator::Comparator() {
    cycles = 1;
    area = 200;
    power = 0.25;
}

Comparator::~Comparator() {}

void Comparator::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = !(*inport[0] == *inport[1]);
}