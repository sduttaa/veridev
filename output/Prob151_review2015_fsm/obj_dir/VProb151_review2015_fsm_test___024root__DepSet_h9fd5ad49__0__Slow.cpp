// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProb151_review2015_fsm_test.h for the primary calling header

#include "VProb151_review2015_fsm_test__pch.h"
#include "VProb151_review2015_fsm_test___024root.h"

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_static__TOP(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_static(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_static\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VProb151_review2015_fsm_test___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__clk__0 = 0U;
}

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_static__TOP(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_static__TOP\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__clk = 0U;
    vlSelfRef.tb__DOT__stim1__DOT__failed = 0U;
}

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_final__TOP(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_final(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_final\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VProb151_review2015_fsm_test___024root___eval_final__TOP(vlSelf);
}

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_final__TOP(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_final__TOP\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0U != vlSelfRef.tb__DOT__stats1__BRA__223__03a192__KET__)) {
        VL_WRITEF_NX("Hint: Output 'shift_ena' has %0d mismatches. First mismatch occurred at time %0d.\n",0,
                     32,vlSelfRef.tb__DOT__stats1__BRA__223__03a192__KET__,
                     32,vlSelfRef.tb__DOT__stats1__BRA__191__03a160__KET__);
    } else {
        VL_WRITEF_NX("Hint: Output 'shift_ena' has no mismatches.\n",0);
    }
    if ((0U != vlSelfRef.tb__DOT__stats1__BRA__159__03a128__KET__)) {
        VL_WRITEF_NX("Hint: Output 'counting' has %0d mismatches. First mismatch occurred at time %0d.\n",0,
                     32,vlSelfRef.tb__DOT__stats1__BRA__159__03a128__KET__,
                     32,vlSelfRef.tb__DOT__stats1__BRA__127__03a96__KET__);
    } else {
        VL_WRITEF_NX("Hint: Output 'counting' has no mismatches.\n",0);
    }
    if ((0U != vlSelfRef.tb__DOT__stats1__BRA__95__03a64__KET__)) {
        VL_WRITEF_NX("Hint: Output 'done' has %0d mismatches. First mismatch occurred at time %0d.\n",0,
                     32,vlSelfRef.tb__DOT__stats1__BRA__95__03a64__KET__,
                     32,vlSelfRef.tb__DOT__stats1__BRA__63__03a32__KET__);
    } else {
        VL_WRITEF_NX("Hint: Output 'done' has no mismatches.\n",0);
    }
    VL_WRITEF_NX("Hint: Total mismatched samples is %1d out of %1d samples\n\nSimulation finished at %0# ps\nMismatches: %1d in %1d samples\n",0,
                 32,vlSelfRef.tb__DOT__stats1__BRA__287__03a256__KET__,
                 32,vlSelfRef.tb__DOT__stats1__BRA__31__03a0__KET__,
                 64,VL_TIME_UNITED_Q(1),32,vlSelfRef.tb__DOT__stats1__BRA__287__03a256__KET__,
                 32,vlSelfRef.tb__DOT__stats1__BRA__31__03a0__KET__);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__stl(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VProb151_review2015_fsm_test___024root___eval_phase__stl(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_settle(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_settle\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VProb151_review2015_fsm_test___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 81, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VProb151_review2015_fsm_test___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__stl(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___dump_triggers__stl\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___stl_sequent__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_stl(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_stl\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 128> VProb151_review2015_fsm_test__ConstPool__TABLE_hd9150080_0;
extern const VlUnpacked<CData/*2:0*/, 256> VProb151_review2015_fsm_test__ConstPool__TABLE_hd195564b_0;
extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_h245db906_0;
extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_hc6261a48_0;
extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_hc5e0ab2b_0;

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___stl_sequent__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___stl_sequent__TOP__0\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ tb__DOT____VdfgRegularize_hf3db91df_0_0;
    tb__DOT____VdfgRegularize_hf3db91df_0_0 = 0;
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.tb__DOT__data) 
                     << 6U) | (((IData)(vlSelfRef.tb__DOT__done_counting) 
                                << 5U) | (((IData)(vlSelfRef.tb__DOT__ack) 
                                           << 4U) | (IData)(vlSelfRef.tb__DOT__good1__DOT__state))));
    vlSelfRef.tb__DOT__good1__DOT__next = VProb151_review2015_fsm_test__ConstPool__TABLE_hd9150080_0
        [__Vtableidx1];
    __Vtableidx3 = ((((IData)(vlSelfRef.tb__DOT__data) 
                      << 7U) | (((IData)(vlSelfRef.tb__DOT__top_module1__DOT__shift_cycle_counter) 
                                 << 5U) | ((IData)(vlSelfRef.tb__DOT__done_counting) 
                                           << 4U))) 
                    | (((IData)(vlSelfRef.tb__DOT__ack) 
                        << 3U) | (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)));
    vlSelfRef.tb__DOT__top_module1__DOT__next_state 
        = VProb151_review2015_fsm_test__ConstPool__TABLE_hd195564b_0
        [__Vtableidx3];
    __Vtableidx2 = vlSelfRef.tb__DOT__good1__DOT__state;
    vlSelfRef.tb__DOT__shift_ena_ref = VProb151_review2015_fsm_test__ConstPool__TABLE_h245db906_0
        [__Vtableidx2];
    vlSelfRef.tb__DOT__counting_ref = VProb151_review2015_fsm_test__ConstPool__TABLE_hc6261a48_0
        [__Vtableidx2];
    vlSelfRef.tb__DOT__done_ref = VProb151_review2015_fsm_test__ConstPool__TABLE_hc5e0ab2b_0
        [__Vtableidx2];
    tb__DOT____VdfgRegularize_hf3db91df_0_0 = (((IData)(vlSelfRef.tb__DOT__shift_ena_ref) 
                                                << 2U) 
                                               | (((IData)(vlSelfRef.tb__DOT__counting_ref) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tb__DOT__done_ref)));
    vlSelfRef.tb__DOT__tb_match = ((IData)(tb__DOT____VdfgRegularize_hf3db91df_0_0) 
                                   == ((IData)(tb__DOT____VdfgRegularize_hf3db91df_0_0) 
                                       ^ ((((4U == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)) 
                                            << 2U) 
                                           | (((5U 
                                                == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)) 
                                               << 1U) 
                                              | (6U 
                                                 == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)))) 
                                          ^ (IData)(tb__DOT____VdfgRegularize_hf3db91df_0_0))));
}

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_triggers__stl(VProb151_review2015_fsm_test___024root* vlSelf);

VL_ATTR_COLD bool VProb151_review2015_fsm_test___024root___eval_phase__stl(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_phase__stl\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VProb151_review2015_fsm_test___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VProb151_review2015_fsm_test___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__act(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___dump_triggers__act\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(edge tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__nba(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___dump_triggers__nba\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(edge tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb.clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___ctor_var_reset(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___ctor_var_reset\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb__DOT__stats1__BRA__287__03a256__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__223__03a192__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__191__03a160__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__159__03a128__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__127__03a96__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__95__03a64__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__63__03a32__KET__ = 0;
    vlSelf->tb__DOT__stats1__BRA__31__03a0__KET__ = 0;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6743979137201610926ull);
    vlSelf->tb__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3335164965398888254ull);
    vlSelf->tb__DOT__data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4256721658738847908ull);
    vlSelf->tb__DOT__done_counting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9143198392249628770ull);
    vlSelf->tb__DOT__ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2962257401066487875ull);
    vlSelf->tb__DOT__shift_ena_ref = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11728180719438387936ull);
    vlSelf->tb__DOT__counting_ref = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2090376511354885311ull);
    vlSelf->tb__DOT__done_ref = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10020345849965530866ull);
    vlSelf->tb__DOT__tb_match = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3576156404782951345ull);
    vlSelf->tb__DOT__stim1__DOT__failed = 0;
    vlSelf->tb__DOT__good1__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6261904464035044633ull);
    vlSelf->tb__DOT__good1__DOT__next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17689656375593603268ull);
    vlSelf->tb__DOT__top_module1__DOT__current_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16554156364323334974ull);
    vlSelf->tb__DOT__top_module1__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12584023579598594017ull);
    vlSelf->tb__DOT__top_module1__DOT__shift_cycle_counter = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 467460021108975211ull);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3935217543338555246ull);
}
