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
    outport = *inport[*ctrlport];
}