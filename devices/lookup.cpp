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
    this->add.control_signals[0] = 0b0110000001010100000000000000000000000000000000000000000000000000; //where are the alu signals for logic, shifter, etc in e0cel? I added them myself
    this->add.control_signals[1] = 0b0000000000000011100000000000000000000000000000000000000000000000;
    this->add.control_signals[2] = 0b0000000000000000001100000000000000000000000000000000000000000000;
    this->add.control_signals[3] = 0b0000000000000000000000001100000000000000000000000000000000000000;
    this->add.control_signals[4] = 0b0000000000000000000000000000001000000000010000000000000000000000;
    this->add.control_signals[5] = 0b0000000000000000000000000000000000000000000000010000000000000000;
    this->add.control_signals[6] = 0b1000000100110000000000000000000000000000000000000000000000100000;
    this->add.control_signals[7] = 0b0000000000000011110000000000000000000000000000000000000000000000;

    this->addi.control_signals[0] = 0b1000000000000000000000000000000000000000000000000000000000000000; //where are the alu signals for logic, shifter, etc in e0cel? I added them myself
    this->addi.control_signals[1] = 0b0000000000000010010000000000000000000000000000000000000000000000;
    this->addi.control_signals[2] = 0b0001010000000000001000010000000000000000000000000000000000000000;
    this->addi.control_signals[3] = 0b0000000000000000000000001100000000000000000000000000000000000000;
    this->addi.control_signals[4] = 0b0000000000000000000000000000001000000000010000000000000000000000;
    this->addi.control_signals[5] = 0b0000000000000000000000000000000000000000000000010000000000000000;
    this->addi.control_signals[6] = 0b1000000100110000000000000000000000000000000000000000000000100000;
    this->addi.control_signals[7] = 0b0000000000000011110000000000000000000000000000000000000000000000;
    /*
    .
    .
    .
    */
    return;
}
void Lookup::populate_table(){
    this->lookup_table[0] = this->add;
    this->lookup_table[1] = this->addi;;
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

