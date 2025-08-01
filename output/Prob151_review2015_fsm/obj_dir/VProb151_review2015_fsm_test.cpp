// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VProb151_review2015_fsm_test__pch.h"

//============================================================
// Constructors

VProb151_review2015_fsm_test::VProb151_review2015_fsm_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VProb151_review2015_fsm_test__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VProb151_review2015_fsm_test::VProb151_review2015_fsm_test(const char* _vcname__)
    : VProb151_review2015_fsm_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VProb151_review2015_fsm_test::~VProb151_review2015_fsm_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VProb151_review2015_fsm_test___024root___eval_debug_assertions(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG
void VProb151_review2015_fsm_test___024root___eval_static(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___eval_initial(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___eval_settle(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___eval(VProb151_review2015_fsm_test___024root* vlSelf);

void VProb151_review2015_fsm_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VProb151_review2015_fsm_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VProb151_review2015_fsm_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VProb151_review2015_fsm_test___024root___eval_static(&(vlSymsp->TOP));
        VProb151_review2015_fsm_test___024root___eval_initial(&(vlSymsp->TOP));
        VProb151_review2015_fsm_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VProb151_review2015_fsm_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VProb151_review2015_fsm_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t VProb151_review2015_fsm_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* VProb151_review2015_fsm_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VProb151_review2015_fsm_test___024root___eval_final(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD void VProb151_review2015_fsm_test::final() {
    VProb151_review2015_fsm_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VProb151_review2015_fsm_test::hierName() const { return vlSymsp->name(); }
const char* VProb151_review2015_fsm_test::modelName() const { return "VProb151_review2015_fsm_test"; }
unsigned VProb151_review2015_fsm_test::threads() const { return 1; }
void VProb151_review2015_fsm_test::prepareClone() const { contextp()->prepareClone(); }
void VProb151_review2015_fsm_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
