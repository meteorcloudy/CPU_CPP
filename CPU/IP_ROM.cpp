#include <iostream>
#include <string>
#include <stdio.h>
#include "IP_ROM.h"
using namespace std;

IP_ROM :: IP_ROM(Wire *_a,Wire * _inst)
{
    a = _a;
    inst = _inst;
    for (int i=0; i<64; i++)
    {
        string name = "00";
        name[1]=i/10+'0';
        name[0]=i%10+'0';
        rom[i].size =32;
        rom[i].name = "rom_" + name;
        rom[i].val = 0;
    }
}

void IP_ROM :: input()
{
    freopen("instruction.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%x",&rom[i].val);
    //printf("%x\n",rom[0].val);
}

void IP_ROM :: run()
{
    if (a->isChange()){
        inst->setVal(rom[a->getVal(7,2)].val);
    }
}












