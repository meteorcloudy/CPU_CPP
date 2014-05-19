#include <iostream>
#include <string>
#include <stdio.h>
#include "alu.h"
using namespace std;

alu :: alu(Wire * _a,Wire * _b,Wire * _aluc,Wire * _wzero,Wire * _zero,Wire * _result)
{
    a = _a;
    b = _b;
    aluc = _aluc;
    wzero = _wzero;
    zero = _zero;
    result = _result;
}

void alu :: run()
{
    if (a->isChange()||b->isChange()||aluc->isChange()||wzero->isChange())
    {
        switch (aluc->val)
        {
            case 0 : result->setVal(a->val & b->val); break;
            case 1 : result->setVal(a->val | b->val); break;
            case 2 : result->setVal(a->val + b->val); break;
            case 3 : result->setVal(a->val - b->val); break;
            case 4 : result->setVal(a->val + b->val); break;
            case 5 : result->setVal(b->val << a->val); break;
            case 6 : result->setVal(b->val >> a->val); break;
            case 7 : result->setVal(b->val >> a->val); break;
        }
        if (wzero->val==1)
        {
            zero->setVal(result->val==0);
        }
    }
}












