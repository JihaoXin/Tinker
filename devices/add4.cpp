#include "add4.hh"

void Add4::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Add4::do_function(){
    // Add 4 bits from inport to outport
    *outport = *inport[0] + 4;
}

void Add4::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}