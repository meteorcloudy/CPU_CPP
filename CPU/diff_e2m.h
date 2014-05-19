#ifndef DIFF_E2M_H_INCLUDED
#define DIFF_E2M_H_INCLUDED

#include <string>
#include "Wire.h"
using namespace std;

class diff_e2m
{
public :
    //input
    Wire * clk;

    Wire * ewreg;
    Wire * em2reg;
    Wire * ewmem;
    Wire * erd;
    Wire * eresult;
    Wire * eqb;
    Wire * esdepend;

    //output
    Wire * mwreg;
    Wire * mm2reg;
    Wire * mwmem;
    Wire * mrd;
    Wire * mresult;
    Wire * mqb;
    Wire * msdepend;

    diff_e2m(
		Wire * clk,
		Wire * ewreg,		Wire * em2reg,		Wire * ewmem,		Wire * erd,		Wire * eresult,
        Wire * eqb,		Wire * esdepend,
		Wire * mwreg,		Wire * mm2reg,		Wire * mwmem,		Wire * mrd,		Wire * mresult,
		Wire * mqb,		Wire * msdepend);
    void run_clk();
};

#endif // DIFF_E2M_H_INCLUDED
