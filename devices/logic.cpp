#include "logic.hh"

Logic::Logic() {
    cycles = 1;
    area = 600;
    power = 0.75;
}

Logic::~Logic() {}

void Logic::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (*ctrlport == 0) { // 0x00 NOT
        outport = ~*inport[0];
    } else if (*ctrlport == 1) { // 0x01 AND
        outport = *inport[0] & *inport[1];
    } else if (*ctrlport == 16) { // 0x10 OR
        outport = *inport[0] | *inport[1];
    } else if (*ctrlport == 17) { // 0x11 XOR
        outport = *inport[0] ^ *inport[1];
    }
}