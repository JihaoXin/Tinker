#ifndef LOGIC_HH
#define LOGIC_HH

class Logic : public Device { 
public:
    Logic(double control) { 
        cycles = 1;
        Area = 600;
        Power = 0.75;
        control = control;
    }
    ~Logic();
    void receive_clock() {outLatch.value = result;}
    void do_function(){ 
        if (control == 0) { // 0x00 NOT
            result = ~in[0];
        } else if (control == 1) { // 0x01 AND
            result = in[0] & in[1];
        } else if (control == 16) { // 0x10 OR
            result = in[0] | in[1];
        } else if (control == 17) { // 0x11 XOR
            result = in[0] ^ in[1];
        }
    }
    void connect(int port_id, Latch l) {in[port_id] = l.value;}
private:
    Port in[2];
    long long result;
    double control;
};

#endif