#include "loadstore.hh"

Loadstore::Loadstore() { 
    cycles = 1;
    area = 20000;
    power = 4.0;

    for(int i = 0; i < 100; i++) {
        mem[i] = 0;
    }
}

Loadstore::~Loadstore() {

}

void Loadstore::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }

    cycle_counter = 0;
    if (*ctrlport == 0) { // 0 to read
        outport[0] = mem[*inport[0]];
    }
    else if (*ctrlport == 1) { // 1 to write
        mem[*inport[0]] = *inport[1];
    }
    else{
        std::cout<<"Wrong Control Signal in LoadStoreUnit."<<std::endl;
    }
    return;
}

