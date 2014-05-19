#include <iostream>
#include <string>
#include <stdio.h>
#include "diff_e2m.h"
using namespace std;

diff_e2m ::  diff_e2m(
    Wire * _clk,
    Wire * _ewreg,		Wire * _em2reg,		Wire * _ewmem,		Wire * _erd,		Wire * _eresult,
    Wire * _eqb,		Wire * _esdepend,
    Wire * _mwreg,		Wire * _mm2reg,		Wire * _mwmem,		Wire * _mrd,		Wire * _mresult,
    Wire * _mqb,		Wire * _msdepend)
{
    clk = _clk;
    ewreg = _ewreg;
    em2reg = _em2reg;
    ewmem = _ewmem;
    erd = _erd;
    eresult = _eresult;
    eqb = _eqb;
    esdepend = _esdepend;
    mwreg = _mwreg;
    mm2reg = _mm2reg;
    mwmem = _mwmem;
    mrd = _mrd;
    mresult = _mresult;
    mqb = _mqb;
    msdepend = _msdepend;
}

void diff_e2m :: run_clk()
{
    if (clk->val==1)
    {
        mwreg->setVal( ewreg->val );
        mm2reg->setVal( em2reg->val );
        mwmem->setVal( ewmem->val );
        mrd->setVal( erd->val );
        mresult->setVal( eresult->val );
        mqb->setVal( eqb->val );
        msdepend->setVal( esdepend->val );
    }
}

















