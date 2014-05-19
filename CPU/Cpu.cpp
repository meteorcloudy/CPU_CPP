#include <string>
#include <stdio.h>
#include "Cpu.h"

using namespace std;

void CPU :: init()
{
    _inst[0].name="F_inst";
    _inst[1].name="D_inst";
    _inst[2].name="E_inst";
    _inst[3].name="M_inst";
    _inst[4].name="W_inst";

    clk.set("clk",1);
    pc.set("pc",32);
    inst.set("inst",32);
    dataout.set("dataout",32);
    result.set("result",32);
    d.set("d",32);
    zero.set("zero",1);
    wreg.set("wreg",1);
    m2reg.set("m2reg",1);
    pcsource.set("pcsource",2);

    rs1.set("rs1",5);
    rs2.set("rs2",5);
    rd.set("rd",5);
    rna.set("rna",5);
    rnb.set("rnb",5);
    wn.set("wn",5);
    sa.set("sa",5);
    qa.set("qa",32);
    qb.set("qb",32);
    a.set("a",32);
    b.set("b",32);
    sst.set("sst",1);
    shift.set("shift",1);
    aluimm.set("aluimm",1);
    sext.set("sext",1);
    wmem.set("wmem",1);
    wzero.set("wzero",1);
    adepend.set("adepend",2);
    bdepend.set("bdepend",2);
    sdepend.set("sdepend",2);
    loaddepend.set("loaddepend",1);
    aluc.set("aluc",4);
    imme.set("imme",16);

    inst_out.set("inst_out",32);
    eximme.set("eximme",32);
    n_pc.set("n_pc",32);
    ex_sa.set("ex_sa",32);
    clk_cnt.set("clk_cnt",32);

    ewreg.set("ewreg",1);
    em2reg.set("em2reg",1);
    eshift.set("eshift",1);
    ealuimm.set("ealuimm",1);
    ewmem.set("ewmem",1);
    ewzero.set("ewzero",1);
    eadepend.set("eadepend",2);
    ebdepend.set("ebdepend",2);
    esdepend.set("esdepend",2);
    ealuc.set("ealuc",4);
    erd.set("erd",5);
    esa.set("esa",5);
    eqa.set("eqa",32);
    eqb.set("eqb",32);
    eeximme.set("eeximme",32);

    mwreg.set("mwreg",1);
    mm2reg.set("mm2reg",1);
    mwmem.set("mwmem",1);
    msdepend.set("msdepend",2);
    mrd.set("mrd",5);
    mresult.set("mresult",32);
    mqb.set("mqb",32);

    wwreg.set("wwreg",1);
    wm2reg.set("wm2reg",1);
    wrd.set("wrd",5);
    wresult.set("wresult",32);
    wdataout.set("wdataout",32);
    pre_d.set("pre_d",32);

    m_data.set("m_data",32);
    InstMem = new IP_ROM(&pc,&inst_out);
    go_pc = new next_pc(&inst,&pcsource,&clk,&loaddepend,&pc,&n_pc);
    control_unit = new Cu(&inst,&zero,&rs1,&rs2,&rd,&erd,&mrd,&ewreg,&mwreg,&em2reg,
                          &wreg,&sst,&m2reg,&shift,&aluimm,&sext,&aluc,&wmem,&pcsource,&adepend,&bdepend,&sdepend,&loaddepend,&wzero);
    rf = new regfile(&rna,&rnb,&d,&wn,&wwreg,&clk,&qa,&qb);
    push_d2e = new diff_d2e(
        &clk,
        &wreg,&m2reg,&shift,&aluimm,&wmem,&wzero,&aluc,&rd,&qa,&qb,&eximme,&sa,&adepend,&bdepend,&sdepend,
        &ewreg,&em2reg,&eshift,&ealuimm,&ewmem,&ewzero,&ealuc,&erd,&eqa,&eqb,&eeximme,&esa,&eadepend,&ebdepend,&esdepend
    );
    alu_unit = new alu(&a,&b,&ealuc,&ewzero,&zero,&result);
    push_e2m = new diff_e2m(
        &clk,
        &ewreg,&em2reg,&ewmem,&erd,&result,&eqb,&esdepend,
        &mwreg,&mm2reg,&mwmem,&mrd,&mresult,&mqb,&msdepend
    );
    DataMem = new IP_RAM(&mwmem,&mresult,&m_data,&clk,&dataout);

    push_m2w = new diff_m2w(
        &clk,
        &mwreg,&mm2reg,&mrd,&mresult,&dataout,
        &wwreg,&wm2reg,&wrd,&wresult,&wdataout
    );

    slct_rnb = new mux2(&rs2,&rd,&sst,&rnb);
    slct_d = new mux2(&wresult,&wdataout,&wm2reg,&d);
    slct_a = new mux4(&eqa,&ex_sa,&mresult,&d,&eadepend,&a);
    slct_b = new mux4(&eqb,&eeximme,&mresult,&d,&ebdepend,&b);
    slct_m_data = new mux4(&mqb,&mqb,&d,&pre_d,&msdepend,&m_data);
}

void CPU :: print()
{
    printf("{\n");
    clk.print();
    pc.print();
    inst.print();
    dataout.print();
    result.print();
    d.print();
    zero.print();
    wreg.print();
    m2reg.print();
    pcsource.print();
    rs1.print();
    rs2.print();
    rd.print();
    rna.print();
    rnb.print();
    wn.print();
    sa.print();
    qa.print();
    qb.print();
    a.print();
    b.print();
    sst.print();
    shift.print();
    aluimm.print();
    sext.print();
    wmem.print();
    wzero.print();
    adepend.print();
    bdepend.print();
    sdepend.print();
    loaddepend.print();
    aluc.print();
    imme.print();
    inst_out.print();
    eximme.print();
    n_pc.print();
    ex_sa.print();
    clk_cnt.print();
    ewreg.print();
    em2reg.print();
    eshift.print();
    ealuimm.print();
    ewmem.print();
    ewzero.print();
    eadepend.print();
    ebdepend.print();
    esdepend.print();
    ealuc.print();
    erd.print();
    esa.print();
    eqa.print();
    eqb.print();
    eeximme.print();
    mwreg.print();
    mm2reg.print();
    mwmem.print();
    msdepend.print();
    mrd.print();
    mresult.print();
    mqb.print();
    wwreg.print();
    wm2reg.print();
    wrd.print();
    wresult.print();
    wdataout.print();
    pre_d.print();
    m_data.print();

    DataMem->print();
    rf->print();

    for (int i=0;i<5;i++)
        _inst[i].print();

    printf("\"py\" : \"good\"\n}");
}

bool CPU :: isChange()
{
    if (clk.isChange()) return true;
    if (pc.isChange()) return true;
    if (inst.isChange()) return true;
    if (dataout.isChange()) return true;
    if (result.isChange()) return true;
    if (d.isChange()) return true;
    if (zero.isChange()) return true;
    if (wreg.isChange()) return true;
    if (m2reg.isChange()) return true;
    if (pcsource.isChange()) return true;
    if (rs1.isChange()) return true;
    if (rs2.isChange()) return true;
    if (rd.isChange()) return true;
    if (rna.isChange()) return true;
    if (rnb.isChange()) return true;
    if (wn.isChange()) return true;
    if (sa.isChange()) return true;
    if (qa.isChange()) return true;
    if (qb.isChange()) return true;
    if (a.isChange()) return true;
    if (b.isChange()) return true;
    if (sst.isChange()) return true;
    if (shift.isChange()) return true;
    if (aluimm.isChange()) return true;
    if (sext.isChange()) return true;
    if (wmem.isChange()) return true;
    if (wzero.isChange()) return true;
    if (adepend.isChange()) return true;
    if (bdepend.isChange()) return true;
    if (sdepend.isChange()) return true;
    if (loaddepend.isChange()) return true;
    if (aluc.isChange()) return true;
    if (imme.isChange()) return true;
    if (inst_out.isChange()) return true;
    if (eximme.isChange()) return true;
    if (n_pc.isChange()) return true;
    if (ex_sa.isChange()) return true;
    if (clk_cnt.isChange()) return true;
    if (ewreg.isChange()) return true;
    if (em2reg.isChange()) return true;
    if (eshift.isChange()) return true;
    if (ealuimm.isChange()) return true;
    if (ewmem.isChange()) return true;
    if (ewzero.isChange()) return true;
    if (eadepend.isChange()) return true;
    if (ebdepend.isChange()) return true;
    if (esdepend.isChange()) return true;
    if (ealuc.isChange()) return true;
    if (erd.isChange()) return true;
    if (esa.isChange()) return true;
    if (eqa.isChange()) return true;
    if (eqb.isChange()) return true;
    if (eeximme.isChange()) return true;
    if (mwreg.isChange()) return true;
    if (mm2reg.isChange()) return true;
    if (mwmem.isChange()) return true;
    if (msdepend.isChange()) return true;
    if (mrd.isChange()) return true;
    if (mresult.isChange()) return true;
    if (mqb.isChange()) return true;
    if (wwreg.isChange()) return true;
    if (wm2reg.isChange()) return true;
    if (wrd.isChange()) return true;
    if (wresult.isChange()) return true;
    if (wdataout.isChange()) return true;
    if (pre_d.isChange()) return true;
    if (m_data.isChange()) return true;

    return false;
}

void CPU :: subChange()
{
    clk.subChange();
    pc.subChange();
    inst.subChange();
    dataout.subChange();
    result.subChange();
    d.subChange();
    zero.subChange();
    wreg.subChange();
    m2reg.subChange();
    pcsource.subChange();
    rs1.subChange();
    rs2.subChange();
    rd.subChange();
    rna.subChange();
    rnb.subChange();
    wn.subChange();
    sa.subChange();
    qa.subChange();
    qb.subChange();
    a.subChange();
    b.subChange();
    sst.subChange();
    shift.subChange();
    aluimm.subChange();
    sext.subChange();
    wmem.subChange();
    wzero.subChange();
    adepend.subChange();
    bdepend.subChange();
    sdepend.subChange();
    loaddepend.subChange();
    aluc.subChange();
    imme.subChange();
    inst_out.subChange();
    eximme.subChange();
    n_pc.subChange();
    ex_sa.subChange();
    clk_cnt.subChange();
    ewreg.subChange();
    em2reg.subChange();
    eshift.subChange();
    ealuimm.subChange();
    ewmem.subChange();
    ewzero.subChange();
    eadepend.subChange();
    ebdepend.subChange();
    esdepend.subChange();
    ealuc.subChange();
    erd.subChange();
    esa.subChange();
    eqa.subChange();
    eqb.subChange();
    eeximme.subChange();
    mwreg.subChange();
    mm2reg.subChange();
    mwmem.subChange();
    msdepend.subChange();
    mrd.subChange();
    mresult.subChange();
    mqb.subChange();
    wwreg.subChange();
    wm2reg.subChange();
    wrd.subChange();
    wresult.subChange();
    wdataout.subChange();
    pre_d.subChange();
    m_data.subChange();
}

void CPU :: prepare()
{
    clk.val=1;
    pc.setVal(0);
    isRunning=true;
    InstMem->input();
    run();
    _inst[0].val=inst_out.val;
}

void CPU :: run_clk()
{
        DataMem->run_clk();
        rf->run_clk();
        if (clk.val==1) pre_d.setVal(d.val);

        push_m2w->run_clk();
        push_e2m->run_clk();
        push_d2e->run_clk();
        if (clk.val==1) {
            for (int i=4;i>=2;i--)
                _inst[i].val=_inst[i-1].val;

            if (loaddepend.val==0)
                inst.setVal(inst_out.val);
        }
        if (clk.val==1&&loaddepend.val==0) pc.setVal(n_pc.val);
        go_pc->run_clk();

}

void CPU :: run()
{
    while (isRunning&&isChange())
    {
        InstMem->run();

        rs1.setVal(inst.getVal(20,16));
        rs2.setVal(inst.getVal(4,0));
        rd.setVal(inst.getVal(25,21));
        eximme.setVal(inst.getVal(15,0));
        ex_sa.setVal(inst.getVal(20,16));

        control_unit->run();
        go_pc->run();

        rna.setVal(rs1.val);
        slct_rnb->run();
        slct_d->run();
        wn.setVal(wrd.val);

        rf->run();

        slct_a->run();
        slct_b->run();

        alu_unit->run();

        slct_m_data->run();
        DataMem->run();

        if (inst_out.val==0)
            isRunning=false;

        subChange();
    }
}










