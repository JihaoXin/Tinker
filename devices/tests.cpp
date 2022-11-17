#include "adder.hh"
#include "comparator.hh"
#include "divider.hh"
#include "logic.hh"
#include "multiplier.hh"
#include "shifter.hh"
#include "two_complement.hh"
#include "register_file.hh"
#include "multiplexer.hh"
#include "demultiplexer.hh"
#include <iostream>

int main () {
    Adder adder;
    Comparator comparator;
    Divider divider;
    // // Logic logic;
    Multiplier multiplier;
    // // Shifter shifter;
    // TwoComplement twocomplement;

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
    truth = (divider.outLatch.value == 0.0)? " TRUE" : " FALSE";
    std::cout << latch1.value << " / " << latch2.value <<  " = "  << divider.outLatch.value << truth << std::endl;

    //negative 
    latch1.value = -395730;
    latch2.value = 2038;
    divider.connect(0, latch1);
    divider.connect(1, latch2);
    divider.do_function();
    divider.receive_clock();
    truth = (divider.outLatch.value == ((int)-395730/(int)2038))? " TRUE" : " FALSE";
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
    Logic logic;
    latch1.value = 3;
    logic.connect(0, latch1);
    logic.do_function(0);
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ~(long long)latch1.value)? " TRUE" : " FALSE";
    std::bitset<64> x(latch1.value);
    std::bitset<64> y(logic.outLatch.value);
    std::cout << "NOT " << x <<  " = "  << y << truth << std::endl;

    // AND
    latch1.value = 85765754;
    latch2.value = 764785;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function(1);
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value & (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x1(latch1.value);
    std::bitset<64> y1(latch2.value);
    std::bitset<64> z1(logic.outLatch.value);
    std::cout << x1 <<  " & "  << y1 << " = "  << z1 << truth << std::endl;

    // OR
    latch1.value = 16;
    latch2.value = 30;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function(16);
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value | (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x2(latch1.value);
    std::bitset<64> y2(latch2.value);
    std::bitset<64> z2(logic.outLatch.value);
    std::cout << x2 <<  " | "  << y2 << " = "  << z2 << truth << std::endl;

    // XOR
    latch1.value = 16;
    latch2.value = 30;
    logic.connect(0, latch1);
    logic.connect(1, latch2);
    logic.do_function(17);
    logic.receive_clock();
    truth = ((long long)logic.outLatch.value == ((long long)latch1.value ^ (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x3(latch1.value);
    std::bitset<64> y3(latch2.value);
    std::bitset<64> z3(logic.outLatch.value);
    std::cout << x3 <<  " ^ "  << y3 << " = "  << z3 << truth << std::endl;

    // shifter
    // right
    Shifter shifter;
    latch1.value = 1024;
    latch2.value = 5;
    shifter.connect(0, latch1);
    shifter.connect(1, latch2);
    shifter.do_function(0);
    shifter.receive_clock();
    truth = (shifter.outLatch.value == ((long long)latch1.value >> (long long) latch2.value))? " TRUE" : " FALSE";
    std::bitset<64> x4(latch1.value);
    std::bitset<64> z4(shifter.outLatch.value);
    std::cout << x4 <<  " >> "  << latch2.value << " = "  << z4 << truth << std::endl;

    // left
    latch1.value = 1024;
    latch2.value = 5;
    shifter.connect(0, latch1);
    shifter.connect(1, latch2);
    shifter.do_function(1);
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

    // register file
    // write to register file for register 5 and 6
    RegisterFile registerFile;
    latch1.value = 12345;
    latch2.value = 5;
    registerFile.connect(0, latch1);
    registerFile.connect(1, latch2);
    registerFile.do_function(17);
    registerFile.receive_clock(17);

    latch1.value = 6789;
    latch2.value = 6;
    registerFile.connect(0, latch1);
    registerFile.connect(1, latch2);
    registerFile.do_function(17);
    registerFile.receive_clock(17);

    // read from register file for register 5 and 6
    latch1.value = 5;
    latch2.value = 6;
    registerFile.connect(0, latch1);
    registerFile.connect(1, latch2);
    registerFile.do_function(16);
    registerFile.receive_clock(16);
    truth = (registerFile.outLatch[0].value == 12345)? " TRUE" : " FALSE";
    std::cout << "register 5 = " << registerFile.outLatch[0].value << truth << std::endl;
    truth = (registerFile.outLatch[1].value == 6789)? " TRUE" : " FALSE";
    std::cout << "register 6 = " << registerFile.outLatch[1].value << truth << std::endl;

    // read registers 5 and 6 individually
    registerFile.connect(0, latch1);
    registerFile.do_function(1);
    registerFile.receive_clock(1);
    truth = (registerFile.outLatch[0].value == 12345)? " TRUE" : " FALSE";
    std::cout << "register 5 = " << registerFile.outLatch[0].value << truth << std::endl;

    latch1.value = 6;
    registerFile.connect(0, latch1);
    registerFile.do_function(1);
    registerFile.receive_clock(1);
    truth = (registerFile.outLatch[0].value == 6789)? " TRUE" : " FALSE";
    std::cout << "register 6 = " << registerFile.outLatch[0].value << truth << std::endl;


    //multiplexer
    Latch latch3;
    Latch latch4;
    Multiplexer multiplexer;
    latch1.value = 1;
    latch2.value = 2;
    latch3.value = 3;
    latch4.value = 4;
    multiplexer.connect(0, latch1);
    multiplexer.connect(1, latch2);
    multiplexer.connect(2, latch3);
    multiplexer.connect(3, latch4);
    multiplexer.do_function(0);
    multiplexer.receive_clock();
    truth = (multiplexer.outLatch.value == latch1.value)? " TRUE" : " FALSE";
    std::cout << "mux 1 = " << multiplexer.outLatch.value << truth << std::endl;

    multiplexer.do_function(1);
    multiplexer.receive_clock();
    truth = (multiplexer.outLatch.value == latch2.value)? " TRUE" : " FALSE";
    std::cout << "mux 2 = " << multiplexer.outLatch.value << truth << std::endl;

    multiplexer.do_function(16);
    multiplexer.receive_clock();
    truth = (multiplexer.outLatch.value == latch3.value)? " TRUE" : " FALSE";
    std::cout << "mux 3 = " << multiplexer.outLatch.value << truth << std::endl;

    multiplexer.do_function(17);
    multiplexer.receive_clock();
    truth = (multiplexer.outLatch.value == latch4.value)? " TRUE" : " FALSE";
    std::cout << "mux 4 = " << multiplexer.outLatch.value << truth << std::endl;

    // demultiplexer
    Demultiplexer demultiplexer;
    latch1.value = 1;
    demultiplexer.connect(0, latch1);
    demultiplexer.do_function();
    demultiplexer.receive_clock(0);
    std::string truth1 = (demultiplexer.outLatch[0].value == latch1.value)? " TRUE" : " FALSE";
    std::string truth2 = (demultiplexer.outLatch[1].value == 0)? " TRUE" : " FALSE";
    std::string truth3 = (demultiplexer.outLatch[2].value == 0)? " TRUE" : " FALSE";
    std::string truth4 = (demultiplexer.outLatch[3].value == 0)? " TRUE" : " FALSE";
    std::cout << "demux 1 = " << demultiplexer.outLatch[0].value << truth << std::endl;
    std::cout << "outLatch[1] = " << demultiplexer.outLatch[1].value << truth << std::endl;
    std::cout << "outLatch[2] = " << demultiplexer.outLatch[2].value << truth << std::endl;
    std::cout << "outLatch[3] = " << demultiplexer.outLatch[3].value << truth << std::endl;

    demultiplexer.receive_clock(1);
    truth1 = (demultiplexer.outLatch[0].value == 0)? " TRUE" : " FALSE";
    truth2 = (demultiplexer.outLatch[1].value == latch1.value)? " TRUE" : " FALSE";
    truth3 = (demultiplexer.outLatch[2].value == 0)? " TRUE" : " FALSE";
    truth4 = (demultiplexer.outLatch[3].value == 0)? " TRUE" : " FALSE";
    std::cout << "demux 2 = " << demultiplexer.outLatch[1].value << truth << std::endl;
    std::cout << "outLatch[0] = " << demultiplexer.outLatch[0].value << truth << std::endl;
    std::cout << "outLatch[2] = " << demultiplexer.outLatch[2].value << truth << std::endl;
    std::cout << "outLatch[3] = " << demultiplexer.outLatch[3].value << truth << std::endl;

    demultiplexer.receive_clock(16);
    truth1 = (demultiplexer.outLatch[0].value == 0)? " TRUE" : " FALSE";
    truth2 = (demultiplexer.outLatch[1].value == 0)? " TRUE" : " FALSE";
    truth3 = (demultiplexer.outLatch[2].value == latch1.value)? " TRUE" : " FALSE";
    truth4 = (demultiplexer.outLatch[3].value == 0)? " TRUE" : " FALSE";
    std::cout << "demux 3 = " << demultiplexer.outLatch[2].value << truth << std::endl;
    std::cout << "outLatch[0] = " << demultiplexer.outLatch[0].value << truth << std::endl;
    std::cout << "outLatch[1] = " << demultiplexer.outLatch[1].value << truth << std::endl;
    std::cout << "outLatch[3] = " << demultiplexer.outLatch[3].value << truth << std::endl;

    demultiplexer.receive_clock(17);
    truth1 = (demultiplexer.outLatch[0].value == 0)? " TRUE" : " FALSE";
    truth2 = (demultiplexer.outLatch[1].value == 0)? " TRUE" : " FALSE";
    truth3 = (demultiplexer.outLatch[2].value == 0)? " TRUE" : " FALSE";
    truth4 = (demultiplexer.outLatch[3].value == latch1.value)? " TRUE" : " FALSE";
    std::cout << "demux 4 = " << demultiplexer.outLatch[3].value << truth << std::endl;
    std::cout << "outLatch[0] = " << demultiplexer.outLatch[0].value << truth << std::endl;
    std::cout << "outLatch[1] = " << demultiplexer.outLatch[1].value << truth << std::endl;
    std::cout << "outLatch[2] = " << demultiplexer.outLatch[2].value << truth << std::endl;





    // demultiplexer.do_function(1);
    // demultiplexer.receive_clock();





    return 0;
};