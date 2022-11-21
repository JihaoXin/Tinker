#include "shifter.hh"

void Shifter::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Shifter::do_function(){
}

 void Shifter::do_function(long long control){
    *outport = (control == 0)? (*inport[0] >> *inport[1]) : (*inport[0] << *inport[1]);
    } // right if control = 0, left if control = 1

void Shifter::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}