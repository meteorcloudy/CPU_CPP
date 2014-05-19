#ifndef IP_ROM_H_INCLUDED
#define IP_ROM_H_INCLUDED

#include <string>
#include "Wire.h"
using namespace std;

class IP_ROM
{
    public :

    //input
    Wire * a;
    //output
    Wire * inst;
    //Reg
    Reg rom[64];
    IP_ROM(Wire * a, Wire * inst);
    void run();
    void input();
};


#endif // IP_ROM_H_INCLUDED
