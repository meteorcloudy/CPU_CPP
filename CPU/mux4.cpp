#include "mux4.h"

mux4 :: mux4(Wire *_a,Wire *_b,Wire *_c,Wire *_d,Wire *_judge,Wire *_out)
{
    a = _a;
    b = _b;
    c = _c;
    d = _d;
    judge = _judge;
    out = _out;
}

void mux4 :: run()
{
    switch (judge->val)
    {
        case 0 :
            out->setVal(a->val);
            break;
        case 1 :
            out->setVal(b->val);
            break;
        case 2 :
            out->setVal(c->val);
            break;
        case 3 :
            out->setVal(d->val);
            break;
    }
}
