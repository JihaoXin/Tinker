#include "two_complement.hh"
TwoComplement::TwoComplement() {
    cycles = 1;
    area = 200;
    power = 0.25;
}

TwoComplement::~TwoComplement() {}
void TwoComplement::receive_clock() {
    outport = -(*inport[0]);
}