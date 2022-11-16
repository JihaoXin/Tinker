#include "latch.hh"
#include "adder.hh"
#include <stdio.h>
#include <iostream>

int main (){

    std::cout << "We out here \n";

    Latch l;
    l.value = 9;

    std::cout << "latch: " << l.value << std::endl;

    Adder adr;
    adr.connect(0, l);

    adr.connect(1, l);

    adr.do_function();
    adr.receive_clock();

    std::cout << adr.outLatch.value << "\n";

    return 0;
}