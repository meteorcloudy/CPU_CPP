#include "mux2.h"

mux2 :: mux2(Wire *_a,Wire *_b,Wire *_judge,Wire *_out)
{
    a = _a;
    b = _b;
    judge = _judge;
    out = _out;
}

void mux2 :: run()
{
    switch (judge->val)
    {
        case 0 : out->setVal(a->val); break;
        case 1 : out->setVal(b->val); break;
    }
}
