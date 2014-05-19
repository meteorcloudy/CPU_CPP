#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

#include <string>
#include "Wire.h"
using namespace std;

class alu
{
    public:
    //input
    Wire * a;
    Wire * b;
    Wire * aluc;
    Wire * wzero;
    //output
    Wire * zero;
    Wire * result;

    alu(Wire * a,Wire * b,Wire * aluc,Wire * wzero,Wire * zero,Wire * result);

    void run();
};

#endif // ALU_H_INCLUDED
