#include "shifter.hh"
Shifter::Shifter() {
    cycles = 1;
    area = 200;
    power = 0.5;
}
Shifter::~Shifter() {}

void Shifter::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = (*ctrlport == 0)? (*inport[0] >> *inport[1]) : (*inport[0] << *inport[1]);
}