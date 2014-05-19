#include <iostream>
#include <string>
#include <stdio.h>
#include "diff_d2e.h"
using namespace std;

diff_d2e :: diff_d2e(
    Wire * _clk,
    Wire * _wreg,		Wire * _m2reg,		Wire * _shift,		Wire * _aluimm,
    Wire * _wmem,		Wire * _wzero,		Wire * _aluc,		Wire * _rd,
    Wire * _qa,		Wire * _qb,		Wire * _eximme,		Wire * _sa, Wire * _adepend,
    Wire * _bdepend,		Wire * _sdepend,
    Wire * _ewreg,		Wire * _em2reg,		Wire * _eshift,		Wire * _ealuimm,
    Wire * _ewmem,		Wire * _ewzero,		Wire * _ealuc,		Wire * _erd,
    Wire * _eqa,		Wire * _eqb,		Wire * _eeximme,		Wire * _esa,
    Wire * _eadepend,		Wire * _ebdepend,		Wire * _esdepend)
{
    clk = _clk;
    wreg = _wreg;
    m2reg = _m2reg;
    shift = _shift;
    aluimm = _aluimm;
    wmem = _wmem;
    wzero = _wzero;
    aluc = _aluc;
    rd = _rd;
    qa = _qa;
    qb = _qb;
    eximme = _eximme;
    sa = _sa;
    adepend = _adepend;
    bdepend = _bdepend;
    sdepend = _sdepend;
    ewreg = _ewreg;
    em2reg = _em2reg;
    eshift = _eshift;
    ealuimm = _ealuimm;
    ewmem = _ewmem;
    ewzero = _ewzero;
    ealuc = _ealuc;
    erd = _erd;
    eqa = _eqa;
    eqb = _eqb;
    eeximme = _eeximme;
    esa = _esa;
    eadepend = _eadepend;
    ebdepend = _ebdepend;
    esdepend = _esdepend;

}

void diff_d2e :: run_clk()
{
    if (clk->val==1)
    {
        ewreg->setVal( wreg->val );
        em2reg->setVal( m2reg->val );
        eshift->setVal( shift->val );
        ealuimm->setVal( aluimm->val );
        ewmem->setVal( wmem->val );
        ewzero->setVal( wzero->val );
        ealuc->setVal( aluc->val );
        erd->setVal( rd->val );
        esa->setVal( sa->val );
        eqa->setVal( qa->val );
        eqb->setVal( qb->val );
        eeximme->setVal( eximme->val );
        eadepend->setVal( adepend->val );
        ebdepend->setVal( bdepend->val );
        esdepend->setVal( sdepend->val );
    }
}

















