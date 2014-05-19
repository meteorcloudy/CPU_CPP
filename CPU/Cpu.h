#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include <string>
#include "Wire.h"
#include "IP_ROM.h"
#include "next_pc.h"
#include "cu.h"
#include "regfile.h"
#include "diff_d2e.h"
#include "alu.h"
#include "diff_e2m.h"
#include "IP_RAM.h"
#include "diff_m2w.h"
#include "mux2.h"
#include "mux4.h"

using namespace std;

class CPU
{
public :
    Wire clk;
    Wire pc;
    Wire inst;
    Wire dataout;
    Wire result;
    Wire d;
    Wire zero;
    Wire wreg;
    Wire m2reg;
    Wire pcsource;


    Wire rs1,rs2,rd,rna,rnb,wn,sa;
    Wire qa,qb,a,b;
    Wire sst,shift,aluimm,sext,wmem,wzero;
    Wire adepend,bdepend,sdepend;
    Wire loaddepend;
    Wire aluc;
    Wire imme;
    Wire inst_out;
    Wire eximme,n_pc,ex_sa;
    Wire clk_cnt;
    Wire ewreg,em2reg,eshift,ealuimm,ewmem,ewzero;
    Wire eadepend,ebdepend,esdepend;
    Wire ealuc;
    Wire erd,esa;
    Wire eqa,eqb,eeximme;
    Wire mwreg,mm2reg,mwmem;
    Wire msdepend;
    Wire mrd;
    Wire mresult,mqb;
    Wire wwreg,wm2reg;
    Wire wrd;
    Wire wresult,wdataout;
    Wire pre_d;
    Wire m_data;

    Wire _inst[5];

    IP_ROM * InstMem;
    next_pc * go_pc;
    Cu * control_unit;
    regfile * rf;
    diff_d2e * push_d2e;
    alu * alu_unit;
    diff_e2m * push_e2m;
    IP_RAM * DataMem;
    diff_m2w * push_m2w;
    mux2 * slct_rnb;
    mux2 * slct_d;
    mux4 * slct_a;
    mux4 * slct_b;
    mux4 * slct_m_data;

    bool isRunning;

    void init();
    void run_clk();
    void run();
    bool isChange();
    void subChange();
    void prepare();
    void print();
};

#endif // CPU_H_INCLUDED















