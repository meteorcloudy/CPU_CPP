#include <iostream>
#include <string>
#include <stdio.h>
#include "regfile.h"
using namespace std;

regfile :: regfile(Wire * _rna, Wire * _rnb, Wire * _d, Wire * _wn, Wire * _we, Wire * _clk, Wire * _qa, Wire * _qb)
{
    rna = _rna;
    rnb = _rnb;
    d = _d;
    wn = _wn;
    we = _we;
    clk = _clk;
    qa = _qa;
    qb = _qb;
    for (int i=0; i<32; i++)
    {
        string name = "00";
        name[0]=i/10+'0';
        name[1]=i%10+'0';
        reg[i].size =32;
        reg[i].name = "reg_" + name;
        reg[i].val = 0;
    }
}

void regfile::run()
{
    //if (rna->isChange()||rnb->isChange())
    {
        qa->setVal(((rna->val==0)?0:reg[rna->val].val));
        qb->setVal(((rnb->val==0)?0:reg[rnb->val].val));
    }
}

void regfile::run_clk()
{
    if (clk->val==0)
    {
        if (wn->val!=0&&we->val==1)
            reg[wn->val].val=d->val;
    }
}


void regfile::print()
{
    for (int i=0;i<10;i++)
        reg[i].print();
}






