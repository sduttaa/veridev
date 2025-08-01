// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VProb151_review2015_fsm_test.h for the primary calling header

#ifndef VERILATED_VPROB151_REVIEW2015_FSM_TEST___024ROOT_H_
#define VERILATED_VPROB151_REVIEW2015_FSM_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class VProb151_review2015_fsm_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) VProb151_review2015_fsm_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__clk;
    CData/*0:0*/ tb__DOT__reset;
    CData/*0:0*/ tb__DOT__data;
    CData/*0:0*/ tb__DOT__done_counting;
    CData/*0:0*/ tb__DOT__ack;
    CData/*0:0*/ tb__DOT__shift_ena_ref;
    CData/*0:0*/ tb__DOT__counting_ref;
    CData/*0:0*/ tb__DOT__done_ref;
    CData/*0:0*/ tb__DOT__tb_match;
    CData/*0:0*/ tb__DOT__stim1__DOT__failed;
    CData/*3:0*/ tb__DOT__good1__DOT__state;
    CData/*3:0*/ tb__DOT__good1__DOT__next;
    CData/*2:0*/ tb__DOT__top_module1__DOT__current_state;
    CData/*2:0*/ tb__DOT__top_module1__DOT__next_state;
    CData/*1:0*/ tb__DOT__top_module1__DOT__shift_cycle_counter;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb__DOT__stats1__BRA__287__03a256__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__223__03a192__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__191__03a160__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__159__03a128__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__127__03a96__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__95__03a64__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__63__03a32__KET__;
    IData/*31:0*/ tb__DOT__stats1__BRA__31__03a0__KET__;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h13ba9e12__0;
    VlTriggerScheduler __VtrigSched_h13ba9e51__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    VProb151_review2015_fsm_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    VProb151_review2015_fsm_test___024root(VProb151_review2015_fsm_test__Syms* symsp, const char* v__name);
    ~VProb151_review2015_fsm_test___024root();
    VL_UNCOPYABLE(VProb151_review2015_fsm_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
