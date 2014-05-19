#ifndef DIFF_M2W_H_INCLUDED
#define DIFF_M2W_H_INCLUDED

#include <string>
#include "Wire.h"
using namespace std;

class diff_m2w
{
    public :
    //input
    Wire * clk;

    Wire * mwreg;
    Wire * mm2reg;
    Wire * mrd;
    Wire * mresult;
    Wire * mdataout;
    //output
    Wire * wwreg;
    Wire * wm2reg;
    Wire * wrd;
    Wire * wresult;
    Wire * wdataout;
    diff_m2w(
        Wire * clk,
		Wire * mwreg,		Wire * mm2reg,		Wire * mrd,		Wire * mresult,		Wire * mdataout,
		Wire * wwreg,		Wire * wm2reg,		Wire * wrd,		Wire * wresult,		Wire * wdataout);
    void run_clk();
};


#endif // DIFF_M2W_H_INCLUDED
