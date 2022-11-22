#include "device.hh"
#include <iostream>
using namespace std;
Device::Device() {
    cycles = 0;
    area = 0;
    power = 0;
    cycle_counter = 0;
}

Device::~Device() {}

void Device::connect(outport_t *p_outport, inport_t &inport) {
    inport = p_outport;
}
