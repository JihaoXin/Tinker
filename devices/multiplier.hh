#ifndef MULTIPLIER_HH
#define MULTIPLIER_HH

class Multiplier : public Device { 
public:
    Multiplier() { 
        cycles = 3;
        Area = 2000;
        Power = 1.5;
    }
    ~Multiplier();
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = in[0] * in[1];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    Port in[2];
    long long result;

}

#endif