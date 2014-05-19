#include <iostream>
#include <string>
#include <stdio.h>
#include "cu.h"
using namespace std;

Cu ::  Cu(Wire * _inst, Wire * _zero, Wire * _rs1, Wire * _rs2, Wire * _rd, Wire * _erd, Wire * _mrd, Wire * _ewreg, Wire * _mwreg, Wire * _esld,
          Wire * _wreg, Wire * _sst, Wire * _m2reg, Wire * _shift, Wire * _aluimm, Wire * _sext, Wire * _aluc, Wire * _wmem, Wire * _pcsource,
          Wire * _adepend, Wire * _bdepend, Wire * _sdepend, Wire * _loaddepend, Wire * _wzero)
{
    inst = _inst;
    zero = _zero;
    rs1 = _rs1;
    rs2 = _rs2;
    rd = _rd;
    erd = _erd;
    mrd = _mrd;
    ewreg = _ewreg;
    mwreg = _mwreg;
    esld = _esld;
    wreg = _wreg;
    sst = _sst;
    m2reg = _m2reg;
    shift = _shift;
    aluimm = _aluimm;
    sext = _sext;
    aluc = _aluc;
    wmem = _wmem;
    pcsource = _pcsource;
    adepend = _adepend;
    bdepend = _bdepend;
    sdepend = _sdepend;
    loaddepend = _loaddepend;
    wzero = _wzero;
}

void Cu :: run()
{
    bool i_and;
    bool i_andi;
    bool i_or;
    bool i_ori;
    bool i_add;
    bool i_addi;
    bool i_sub;
    bool i_subi;
    bool i_load;
    bool i_store;
    bool i_beq;
    bool i_bne;
    bool i_branch;
    bool i_sll;
    bool i_srl;
    bool i_sra;
    bool eequ_rs1;
    bool mequ_rs1;
    bool eequ_rs2;
    bool mequ_rs2;
    bool erd_equ;
    bool mrd_equ;
    bool rs2isReg;

    bool isloaddepend;

    if (inst->isChange()||zero->isChange()||rs1->isChange()||rs2->isChange()||rd->isChange()||erd->isChange()||
            mrd->isChange()||ewreg->isChange()||mwreg->isChange()||esld->isChange())
    {
        int op = inst->getVal(31,26);
        i_and = ( op == 0 );
        i_andi = ( op == 1 );
        i_or = ( op == 2 );
        i_ori = ( op == 3 );
        i_add = ( op == 4 );
        i_addi = ( op == 5 );
        i_sub = ( op == 6 );
        i_subi = ( op == 7 );
        i_load = ( op == 8 );
        i_store = ( op == 9 );
        i_beq = ( op == 10 );
        i_bne = ( op == 11 );
        i_branch = ( op == 12 );
        i_sll = ( op == 13 );
        i_srl = ( op == 14 );
        i_sra = ( op == 15 );


        eequ_rs1 = (rs1->val == erd->val );
        mequ_rs1 = (rs1->val == mrd->val );
        eequ_rs2 = (rs2->val == erd->val );
        mequ_rs2 = (rs2->val == mrd->val );
        erd_equ = (rd->val == erd->val );
        mrd_equ = (rd->val == mrd->val );
        rs2isReg = i_and|i_or|i_add|i_sub|i_sll|i_srl|i_sra;

        adepend->setVal(1,((ewreg->val&&eequ_rs1)||(mwreg->val&&mequ_rs1))&&!shift->val);
        adepend->setVal(0,(mwreg->val&&mequ_rs1&&(!ewreg->val||!eequ_rs1))||shift->val);

        bdepend->setVal(1,rs2isReg&&((ewreg->val&&eequ_rs2)||(mwreg->val&&mequ_rs2)));
        bdepend->setVal(0,!rs2isReg||(mwreg->val&&mequ_rs2&&(!ewreg->val||!eequ_rs2)));

        isloaddepend =  esld->val && ( (adepend->getVal(1)&&!adepend->getVal(0)) || (bdepend->getVal(1)&&!bdepend->getVal(0)) );

        wreg->setVal((i_and||i_andi||i_or||i_ori||i_add|| i_addi||i_sub||i_subi||i_load||i_sll||i_srl||i_sra)&&!isloaddepend);
        sst->setVal(i_store);
        m2reg->setVal(i_load);
        shift->setVal(i_sll||i_srl||i_sra);
        aluimm->setVal(i_andi||i_ori||i_addi||i_subi||i_store||i_load);
        sext->setVal(i_addi||i_subi);
        wmem->setVal(i_store&&!isloaddepend);

        loaddepend->setVal(isloaddepend);
        wzero->setVal((i_add||i_addi||i_sub||i_subi)&&!isloaddepend);

        aluc->setVal(3,i_beq||i_bne||i_branch);
        aluc->setVal(2,i_load||i_store||i_sll||i_srl||i_sra);
        aluc->setVal(1,i_add||i_sub||i_srl||i_sra||i_addi||i_subi);
        aluc->setVal(0,i_or||i_ori||i_sub||i_subi||i_sll||i_sra);

        pcsource->setVal(1,i_branch);
        pcsource->setVal(0,i_branch||(i_beq&&zero->val)||(i_bne&&(!zero->val)));

        sdepend->setVal(1,((ewreg->val&&erd_equ)||(mwreg->val&&mrd_equ))&&i_store);
        sdepend->setVal(0,(mwreg->val&&mrd_equ&&(!ewreg->val||!erd_equ))&&i_store);
    }
}





















