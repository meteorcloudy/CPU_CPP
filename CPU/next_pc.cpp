#include <iostream>
#include <string>
#include <stdio.h>
#include "next_pc.h"
using namespace std;

next_pc :: next_pc(Wire * _inst, Wire * _pc_source, Wire * _clk, Wire * _loaddepend, Wire * _pc, Wire * _npc)
{
    inst = _inst;
    pc_source = _pc_source;
    clk = _clk;
    loaddepend = _loaddepend;
    pc = _pc;
    npc = _npc;
}

void next_pc :: run_clk()
{
    if (clk->val==1)
    {

    }
}

void next_pc :: run()
{
    int pcInc = pc->val + 4;
    int branchAdd = (pc->getVal(31,26)<<26) + inst->getVal(25,0);
    int jumpAdd = inst->getVal(15,0);

    switch (pc_source->val)
    {
    case 0 :
        next.setVal(pcInc);
        break;
    case 1 :
        next.setVal(jumpAdd);
        break;
    case 2 :
        next.setVal(pcInc);
        break;
    case 3 :
        next.setVal(branchAdd);
        break;
    }
    npc->setVal(next.val);
}








