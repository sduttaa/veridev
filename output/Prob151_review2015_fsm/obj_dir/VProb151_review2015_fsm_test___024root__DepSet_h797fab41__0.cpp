// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProb151_review2015_fsm_test.h for the primary calling header

#include "VProb151_review2015_fsm_test__pch.h"
#include "VProb151_review2015_fsm_test__Syms.h"
#include "VProb151_review2015_fsm_test___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__act(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG

void VProb151_review2015_fsm_test___024root___eval_triggers__act(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_triggers__act\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb__DOT__clk) 
                                          ^ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0)));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.tb__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 
        = vlSelfRef.tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VProb151_review2015_fsm_test___024root___dump_triggers__act(vlSelf);
    }
#endif
}
