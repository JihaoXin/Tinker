#include "lookup.hh"
#include "types.hh"

Lookup::Lookup() {
    cycles = 0.5;
    area = 500;
    power = 0.25;
    // lookup_table.insert({0, (unsigned long long) 0b});
    this->populate_signals();
    this->populate_table();
}

Lookup::~Lookup() {this->lookup_table.clear();}

void Lookup::populate_signals(){
    this->add.control_signals[0] = 0b00000101010000000000000000000000000; //where are the alu signals for logic, shifter, etc in excel? I added them myself
    this->add.control_signals[1] = 0b00000000001000000000000000000000000;
    this->add.control_signals[2] = 0b00000000000000000000000000000000000;
    this->add.control_signals[3] = 0b00000000000000000000000000000000000;
    this->add.control_signals[4] = 0b00000000000000000000000000000000000;
    this->add.control_signals[5] = 0b00000000000000000000000000000000000;
    this->add.control_signals[6] = 0b00010011000000000000000000000000000;
    this->add.control_signals[7] = 0b00000000001100000000000000000000000;
    /*
    .
    .
    .
    */
    return;
}
void Lookup::populate_table(){
    this->lookup_table[0] = this->add;
    return;
}

void Lookup::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = this->lookup_table[*inport[0]];
}

