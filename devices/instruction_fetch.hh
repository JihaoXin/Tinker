#ifndef INSTRUCTIONFETCH_HH
#define INSTRUCTIONFETCH_HH
#include "device.hh"
#include <array>
#include <iostream>
#include <fstream>

class InstructionFetch : public Device {
public:
    InstructionFetch(char const* filename) {
      //Open the binary file of instructions

      instructionFile.open(filename, std::ios::out | std::ios::binary);
      if(!instructionFile) {
        std::cout << "Cannot open instruction file" << std::endl;
      }
    }
    ~InstructionFetch() {
      instructionFile.close();
    }
    void receive_clock() {}
    void do_function(uint32_t PC) {}
    void do_function() {}
    void connect(int port_id, Latch inLatch) {}

    Latch outLatch;
private:
    std::array<Port, 2> inport;
    Port outport;

    std::ifstream instructionFile;
    

};

#endif