#ifndef MUX2_H_INCLUDED
#define MUX2_H_INCLUDED

#include "Wire.h"

class mux2
{
public :

//input
    Wire *a;
    Wire *b;
    Wire *judge;
//output
    Wire *out;

    mux2(Wire *a,Wire *b,Wire *judge,Wire *out);
    void run();
};

#endif // MUX2_H_INCLUDED
