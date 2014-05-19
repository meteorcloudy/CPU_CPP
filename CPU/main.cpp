#include <iostream>
#include <stdio.h>
#include "Cpu.h"
using namespace std;

int main()
{
    CPU py;
    freopen("info.json","w",stdout);
    py.init();
    py.prepare();
    int cnt=0;
    bool flag = false;
    printf("[\n");
    while (py.isRunning)
    {
        if (flag) printf("\n,\n");
        flag=true;
        py.print();
        cnt++;
        py.clk.val=1-py.clk.val;
        py.run_clk();
        py.run();
        py._inst[1].val = py.inst.val;
        py._inst[0].val = py.inst_out.val;
    }
    printf("\n]");

    return 0;
}
