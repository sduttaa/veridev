// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProb151_review2015_fsm_test.h for the primary calling header

#include "VProb151_review2015_fsm_test__pch.h"
#include "VProb151_review2015_fsm_test__Syms.h"
#include "VProb151_review2015_fsm_test___024root.h"

void VProb151_review2015_fsm_test___024root___ctor_var_reset(VProb151_review2015_fsm_test___024root* vlSelf);

VProb151_review2015_fsm_test___024root::VProb151_review2015_fsm_test___024root(VProb151_review2015_fsm_test__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VProb151_review2015_fsm_test___024root___ctor_var_reset(this);
}

void VProb151_review2015_fsm_test___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VProb151_review2015_fsm_test___024root::~VProb151_review2015_fsm_test___024root() {
}
