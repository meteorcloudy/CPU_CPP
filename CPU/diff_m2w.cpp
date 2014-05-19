#include <iostream>
#include <string>
#include <stdio.h>
#include "diff_m2w.h"
using namespace std;

diff_m2w :: diff_m2w(
    Wire * _clk,
    Wire * _mwreg,		Wire * _mm2reg,		Wire * _mrd,		Wire * _mresult,		Wire * _mdataout,
    Wire * _wwreg,		Wire * _wm2reg,		Wire * _wrd,		Wire * _wresult,		Wire * _wdataout)
{
    clk = _clk;

    mwreg = _mwreg;
    mm2reg = _mm2reg;
    mrd = _mrd;
    mresult = _mresult;
    mdataout = _mdataout;

    wwreg = _wwreg;
    wm2reg = _wm2reg;
    wrd = _wrd;
    wresult = _wresult;
    wdataout = _wdataout;
}

void diff_m2w :: run_clk()
{
    if (clk->val==1)
    {
        wwreg->setVal( mwreg->val );
        wm2reg->setVal( mm2reg->val );
        wrd->setVal( mrd->val );
        wresult->setVal( mresult->val );
        wdataout->setVal( mdataout->val );
    }
}
