// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProb151_review2015_fsm_test.h for the primary calling header

#include "VProb151_review2015_fsm_test__pch.h"
#include "VProb151_review2015_fsm_test__Syms.h"
#include "VProb151_review2015_fsm_test___024root.h"

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_initial__TOP(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_initial__TOP\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"wave.vcd"});
    VL_PRINTF_MT("-Info: /Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv:120: $dumpvar ignored, as Verilated without --trace\n");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__stl(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_triggers__stl(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_triggers__stl\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VProb151_review2015_fsm_test___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
