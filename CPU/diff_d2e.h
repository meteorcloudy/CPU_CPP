#ifndef DIFF_D2E_H_INCLUDED
#define DIFF_D2E_H_INCLUDED
#include <string>
#include "Wire.h"
using namespace std;

class diff_d2e
{
public :
    //input
    Wire * clk;

    Wire * wreg;
    Wire * m2reg;
    Wire * shift;
    Wire * aluimm;
    Wire * wmem;
    Wire * wzero;
    Wire * aluc;
    Wire * rd;
    Wire * qa;
    Wire * qb;
    Wire * eximme;
    Wire * sa;
    Wire * adepend;
    Wire * bdepend;
    Wire * sdepend;

    //output
    Wire * ewreg;
    Wire * em2reg;
    Wire * eshift;
    Wire * ealuimm;
    Wire * ewmem;
    Wire * ewzero;
    Wire * ealuc;
    Wire * erd;
    Wire * eqa;
    Wire * eqb;
    Wire * eeximme;
    Wire * esa;
    Wire * eadepend;
    Wire * ebdepend;
    Wire * esdepend;

    diff_d2e(Wire * clk,
             Wire * wreg,	Wire * m2reg,	Wire * shift,	Wire * aluimm,	Wire * wmem,
             Wire * wzero,	Wire * aluc,	Wire * rd,	Wire * qa,	Wire * qb,	Wire * eximme,
             Wire * sa,	    Wire * adepend,	    Wire * bdepend,	    Wire * sdepend,

             Wire * ewreg,	Wire * em2reg,	Wire * eshift,	Wire * ealuimm,	Wire * ewmem,
             Wire * ewzero,	Wire * ealuc,	Wire * erd,	Wire * eqa,	Wire * eqb, Wire * eeximme,
             Wire * esa,	Wire * eadepend,    Wire * ebdepend,    Wire * esdepend);

    void run_clk();
};

#endif // DIFF_D2E_H_INCLUDED















