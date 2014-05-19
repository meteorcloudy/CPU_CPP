#include <iostream>
#include <string>
#include <stdio.h>
#include "IP_RAM.h"
using namespace std;

IP_RAM :: IP_RAM(Wire * _we, Wire * _addr, Wire * _datain, Wire * _clk, Wire * _dataout)
{
    we = _we;
    addr = _addr;
    datain = _datain;
    clk = _clk;
    dataout = _dataout;
    for (int i=0; i<32; i++)
    {
        string name = "00";
        name[0]=i/10+'0';
        name[1]=i%10+'0';
        ram[i].size =32;
        ram[i].name = "ram_" + name;
        ram[i].val = 0;
    }
    ram[0].val = 126;
}

void IP_RAM :: run_clk()
{
    if (clk->val==1){
        if (we->val==1)
            ram[addr->getVal(6,2)].val = datain->val;
    }
}

void IP_RAM :: run()
{
    //if (addr->isChange())
    {
        dataout->setVal(ram[addr->getVal(6,2)].val);
    }
}

void IP_RAM :: print()
{
    for (int i=0;i<10;i++)
        ram[i].print();
}












