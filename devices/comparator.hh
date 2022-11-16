#ifndef COMPARATOR_HH
#define COMPARATOR_HH

class Comparator : public Device {
public:
    Comparator() { 
        cycles = 1;
        Area = 200;
        Power = 0.25;
    }
    ~Comparator();
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = !(in[0] == in[1]);}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    Port in[2];
    long long result;

};

#endif