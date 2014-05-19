#ifndef IP_RAM_H_INCLUDED
#define IP_RAM_H_INCLUDED
#include <string>
#include "Wire.h"
using namespace std;

class IP_RAM
{
    public :
    //input
    Wire * we;
    Wire * addr;
    Wire * datain;
    Wire * clk;
    //output
    Wire * dataout;
    //reg
    Reg ram[32];

    IP_RAM(Wire * we, Wire * addr, Wire * datain, Wire * clk, Wire * dataout);

    void run();
    void run_clk();
    void print();
};


#endif // IP_RAM_H_INCLUDED
