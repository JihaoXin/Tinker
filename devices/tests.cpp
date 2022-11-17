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

    Latch latch1;
    Latch latch2;

    // adder
    // positive
    latch1.value = 1;
    latch2.value = 2;
    adder.connect(0, latch1);
    adder.connect(1, latch2);
    adder.do_function();
    adder.receive_clock();
    std::string truth = (adder.outLatch.value == 3)? " TRUE" : " FALSE";
    std::cout << latch1.value << " + " << latch2.value <<  " = "  << adder.outLatch.value << truth << std::endl;

    //negative 
    latch1.value = -1;
    latch2.value = -2;
    adder.connect(0, latch1);
    adder.connect(1, latch2);
    adder.do_function();
    adder.receive_clock();
    truth = (adder.outLatch.value == -3)? " TRUE" : " FALSE";
    std::cout << "Adder -1 + -2 = " << adder.outLatch.value << truth << std::endl;

    //comparator
    //not equals 
    latch1.value = 1;
    latch2.value = 2;
    comparator.connect(0, latch1);
    comparator.connect(1, latch2);
    comparator.do_function();
    comparator.receive_clock();
    truth = (comparator.outLatch.value == 0)? " TRUE" : " FALSE";
    std::cout << latch1.value << " == " << latch2.value <<  " = "  << comparator.outLatch.value << truth << std::endl;

    //equals 
    latch1.value = 1;
    latch2.value = 1;
    comparator.connect(0, latch1);
    comparator.connect(1, latch2);
    comparator.do_function();
    comparator.receive_clock();
    truth = (comparator.outLatch.value == 0)? " TRUE" : " FALSE";
    std::cout << latch1.value << " == " << latch2.value <<  " = "  << comparator.outLatch.value << truth << std::endl;

    //divider
    // positive
    latch1.value = 1;
    latch2.value = 2;
    divider.connect(0, latch1);
    divider.connect(1, latch2);
    divider.do_function();
    divider.receive_clock();
    truth = (divider.outLatch.value == 0.5)? " TRUE" : " FALSE";
    std::cout << latch1.value << " / " << latch2.value <<  " = "  << divider.outLatch.value << truth << std::endl;

    //negative 
    latch1.value = -395730;
    latch2.value = 2038;
    divider.connect(0, latch1);
    divider.connect(1, latch2);
    divider.do_function();
    divider.receive_clock();
    truth = (divider.outLatch.value == ((double)-395730/(double)2038))? " TRUE" : " FALSE";
    std::cout << latch1.value << " / " << latch2.value <<  " = "  << divider.outLatch.value << truth << std::endl;

    //multiplier
    // positive
    latch1.value = 395730.2;
    latch2.value = 2038.5;
    multiplier.connect(0, latch1);
    multiplier.connect(1, latch2);
    multiplier.do_function();
    multiplier.receive_clock();
    truth = (multiplier.outLatch.value == ((double)395730.2*(double)2038.5))? " TRUE" : " FALSE";
    std::cout << latch1.value << " * " << latch2.value <<  " = "  << multiplier.outLatch.value << truth << std::endl;

    //negative
    latch1.value = -395730.2;
    latch2.value = 2038.5;
    multiplier.connect(0, latch1);
    multiplier.connect(1, latch2);
    multiplier.do_function();
    multiplier.receive_clock();
    truth = (multiplier.outLatch.value == ((double)-395730.2*(double)2038.5))? " TRUE" : " FALSE";
    std::cout << latch1.value << " * " << latch2.value <<  " = "  << multiplier.outLatch.value << truth << std::endl;

    // logic
    // NOT
    Logic logic(0);
    latch1.value = 3;
    logic.connect(0, latch1);
    logic.do_function();
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ~(long long)latch1.value)? " TRUE" : " FALSE";
    std::bitset<64> x(latch1.value);
    std::bitset<64> y(logic.outLatch.value);
    std::cout << "NOT " << x <<  " = "  << y << truth << std::endl;
    // delete(logic)

    // AND
    logic = Logic(1);
    latch1.value = 85765754;
    latch2.value = 764785;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function();
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value & (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x1(latch1.value);
    std::bitset<64> y1(latch2.value);
    std::bitset<64> z1(logic.outLatch.value);
    std::cout << x1 <<  " & "  << y1 << " = "  << z1 << truth << std::endl;

    // OR
    logic = Logic(16);
    latch1.value = 16;
    latch2.value = 30;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function();
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value | (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x2(latch1.value);
    std::bitset<64> y2(latch2.value);
    std::bitset<64> z2(logic.outLatch.value);
    std::cout << x2 <<  " | "  << y2 << " = "  << z2 << truth << std::endl;

    // XOR
    logic = Logic(17);
    latch1.value = 16;
    latch2.value = 30;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function();
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value ^ (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x3(latch1.value);
    std::bitset<64> y3(latch2.value);
    std::bitset<64> z3(logic.outLatch.value);
    std::cout << x3 <<  " ^ "  << y3 << " = "  << z3 << truth << std::endl;

    // shifter
    // right
    Shifter shifter(0);
    latch1.value = 1024;
    latch2.value = 5;
    shifter.connect(0, latch1);
    shifter.connect(1, latch2);
    shifter.do_function();
    shifter.receive_clock();
    truth = (shifter.outLatch.value == ((long long)latch1.value >> (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x4(latch1.value);
    std::bitset<64> z4(shifter.outLatch.value);
    std::cout << x4 <<  " >> "  << latch2.value << " = "  << z4 << truth << std::endl;

    // left
    shifter = Shifter(1);
    latch1.value = 1024;
    latch2.value = 5;
    shifter.connect(0, latch1);
    shifter.connect(1, latch2);
    shifter.do_function();
    shifter.receive_clock();
    truth = (shifter.outLatch.value == ((long long)latch1.value << (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x5(latch1.value);
    std::bitset<64> z5(shifter.outLatch.value);
    std::cout << x5 <<  " << "  << latch2.value << " = "  << z5 << truth << std::endl;

    // two's complement
    // positive
    TwoComplement twoComplement;
    latch1.value = 1024;
    twoComplement.connect(0, latch1);
    twoComplement.do_function();
    twoComplement.receive_clock();
    truth = (twoComplement.outLatch.value == -latch1.value)? " TRUE" : " FALSE";
    std::bitset<64> x6(latch1.value);
    std::bitset<64> z6(twoComplement.outLatch.value);
    std::cout << x6 <<  " two's complement = "  << z6 << truth << std::endl;

    // negative
    latch1.value = -1024;
    twoComplement.connect(0, latch1);
    twoComplement.do_function();
    twoComplement.receive_clock();
    truth = (twoComplement.outLatch.value == -latch1.value)? " TRUE" : " FALSE";
    std::bitset<64> x7(latch1.value);
    std::bitset<64> z7(twoComplement.outLatch.value);
    std::cout << x7 <<  " two's complement = "  << z7 << truth << std::endl;
    
    






    // double a = 3;
    // // double c = 3;
    // long long b = ~(long long)a;
    // double c = b;
    // std::bitset<64> x(a);
    // std::bitset<64> y((long long)c);
    // // std::bitset<64> t(c);
    // // print a and b
    // std::cout << "a = " << x << std::endl;
    // std::cout << "c = " << y << std::endl;
    // // std::cout << "c = " << t << std::endl;





    return 0;
};