#ifndef CU_H_INCLUDED
#define CU_H_INCLUDED
#include <string>
#include "Wire.h"
using namespace std;

class Cu
{
public :
    //input
    Wire * inst;
    Wire * zero;
    Wire * rs1;
    Wire * rs2;
    Wire * rd;
    Wire * erd;
    Wire * mrd;
    Wire * ewreg;
    Wire * mwreg;
    Wire * esld;
    //output
    Wire * wreg;
    Wire * sst;
    Wire * m2reg;
    Wire * shift;
    Wire * aluimm;
    Wire * sext;
    Wire * aluc;
    Wire * wmem;
    Wire * pcsource;
    Wire * adepend;
    Wire * bdepend;
    Wire * sdepend;
    Wire * loaddepend;
    Wire * wzero;

    Cu(Wire * inst, Wire * zero, Wire * rs1, Wire * rs2, Wire * rd, Wire * erd, Wire * mrd, Wire * ewreg, Wire * mwreg, Wire * esld,
       Wire * wreg, Wire * sst, Wire * m2reg, Wire * shift, Wire * aluimm, Wire * sext, Wire * aluc, Wire * wmem, Wire * pcsource,
       Wire * adepend, Wire * bdepend, Wire * sdepend, Wire * loaddepend, Wire * wzero);

    void run();
};

#endif // CU_H_INCLUDED





























