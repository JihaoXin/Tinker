#ifndef SHIFTER_HH
#define SHIFTER_HH

class Shifter : public Device {
public:
    Shifter(double control) { 
        cycles = 1;
        Area = 200;
        Power = 0.5;
        control = control;
    }
    ~Shifter();
    void receive_clock() {outLatch.value = result;}
    void do_function(){ result = (in[0] >> in[1]) if control == 0 else (in[0] << in[1]);}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}
private:
    Port in[2];
    long long result;
    double control;
};

#endif