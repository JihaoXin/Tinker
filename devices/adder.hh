#ifndef ADDER_HH
#define ADDER_HH

class Adder : public Device {
public:
    Adder() { 
        cycles = 1;
        Area = 400;
        Power = 0.5;
    }
        
    ~Adder();
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = in[0] + in[1];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

    private:
    Port in[2];
    long long result;

}


#endif