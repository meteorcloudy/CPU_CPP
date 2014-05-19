#ifndef NEXT_PC_H_INCLUDED
#define NEXT_PC_H_INCLUDED
#include <string>
#include "Wire.h"
using namespace std;

class next_pc
{
    public:
    //input
    Wire * inst;
    Wire * pc_source;
    Wire * clk;
    Wire * loaddepend;
    Wire * pc;
    //output
    Wire * npc;

    //
    Wire next;

    next_pc(Wire * inst, Wire * pc_source, Wire * clk, Wire * loaddepend, Wire * pc, Wire * npc);
    void run_clk();
    void run();
};

#endif // NEXT_PC_H_INCLUDED
