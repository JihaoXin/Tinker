   #include "multiplexer.hh"

Multiplexer::Multiplexer() {
    cycles = 0.5;
    area = 500;
    power = 0.25;
}

Multiplexer::~Multiplexer() {}

void Multiplexer::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (*ctrlport == 0) {
        outport = *inport[0];
    } else if (*ctrlport == 1) {
        outport = *inport[1];
    } else if (*ctrlport == 16) {
        outport = *inport[2];
    } else if (*ctrlport == 17) {
        outport = *inport[3];
    } 
}