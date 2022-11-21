#include "demultiplexer.hh"
void Demultiplexer::receive_clock(){}
void Demultiplexer::do_function(){
    *outport = *inport[0];
}
void Demultiplexer::receive_clock(long long control) {
    if (control == 0) {
        outLatch[0].value = reinterpret_cast<unsigned char*>(outport);
        *outLatch[1].value = 0;
        *outLatch[2].value = 0;
        *outLatch[3].value = 0;
    } else if (control == 1) {
        *outLatch[0].value = 0;
        outLatch[1].value = reinterpret_cast<unsigned char*>(outport);
        *outLatch[2].value = 0;
        *outLatch[3].value = 0;
    } else if (control == 16) {
        *outLatch[0].value = 0;
        *outLatch[1].value = 0;
        outLatch[2].value = reinterpret_cast<unsigned char*>(outport);
        *outLatch[3].value = 0;
    } else if (control == 17) {
        *outLatch[0].value = 0;
        *outLatch[1].value = 0;
        *outLatch[2].value = 0;
        outLatch[3].value = reinterpret_cast<unsigned char*>(outport);;
    } 
}
void Demultiplexer::do_function(){
    *outport = *inport[0];
}

void Demultiplexer::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}