#include "add4.hh"

void Add4::receive_clock() {
    outLatch.value = result;
}

void Add4::do_function(){
    result = in[0] + 4;
}

void Add4::connect(int port_id, Latch l){
    in[port_id] = l.value;
}