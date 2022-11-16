#include "adder.hh"
#include "comparator.hh"
#include "divider.hh"
#include "logic.hh"
#include "multiplier.hh"
#include "shifter.hh"
#include "twocomplement.hh"
#include <iostream>

int main () {
    Adder adder;
    Comparator comparator;
    Divider divider;
    // Logic logic;
    Multiplier multiplier;
    // Shifter shifter;
    TwoComplement twocomplement;

    Latch latch;
    latch.value = 1;
    adder.connect(0, latch);
    latch.value = 2;
    adder.connect(1, latch);
    adder.do_function();
    adder.receive_clock();

    // initialize string to "TRUE" 
    std::string truth = (adder.outLatch.value == 3)? " TRUE" : " FALSE";
    std::cout << "Adder 1 + 2 = " << adder.outLatch.value << truth << std::endl;



    return 0;
};