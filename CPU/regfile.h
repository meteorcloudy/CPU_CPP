#ifndef REGFILE_H_INCLUDED
#define REGFILE_H_INCLUDED
#include <string>
#include "Wire.h"

class regfile
{
    public:
    //input
    Wire * we;
    Wire * clk;
    Wire * rna;
    Wire * rnb;
    Wire * d;
    Wire * wn;
    //output
    Wire * qa;
    Wire * qb;

    Reg reg[32];

    regfile(Wire * rna, Wire * rnb, Wire * d, Wire * wn, Wire * we, Wire * clk, Wire * qa, Wire * qb);
    void run();
    void run_clk();
    void print();
};

#endif // REGFILE_H_INCLUDED
