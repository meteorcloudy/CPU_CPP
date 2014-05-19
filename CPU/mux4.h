#ifndef MUX4_H_INCLUDED
#define MUX4_H_INCLUDED
#include "Wire.h"

class mux4
{
public :

//input
    Wire *a;
    Wire *b;
    Wire *c;
    Wire *d;
    Wire *judge;
//output
    Wire *out;

    mux4(Wire *a,Wire *b,Wire *c,Wire *d,Wire *judge,Wire *out);
    void run();
};

#endif // MUX4_H_INCLUDED
