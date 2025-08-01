// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VProb151_review2015_fsm_test.h for the primary calling header

#include "VProb151_review2015_fsm_test__pch.h"
#include "VProb151_review2015_fsm_test___024root.h"

VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___eval_initial__TOP(VProb151_review2015_fsm_test___024root* vlSelf);
VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__0(VProb151_review2015_fsm_test___024root* vlSelf);
VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__1(VProb151_review2015_fsm_test___024root* vlSelf);
VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__2(VProb151_review2015_fsm_test___024root* vlSelf);

void VProb151_review2015_fsm_test___024root___eval_initial(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_initial\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VProb151_review2015_fsm_test___024root___eval_initial__TOP(vlSelf);
    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VL_INLINE_OPT VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__0(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                             105);
        vlSelfRef.tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__1(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                         202);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 204, "");
}

VL_INLINE_OPT VlCoroutine VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__2(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_initial__TOP__Vtiming__2\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5;
    tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0;
    // Body
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         20);
    vlSelfRef.tb__DOT__stim1__DOT__failed = 0U;
    vlSelfRef.tb__DOT__reset = 1U;
    vlSelfRef.tb__DOT__data = 0U;
    vlSelfRef.tb__DOT__done_counting = 0U;
    vlSelfRef.tb__DOT__ack = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         26);
    vlSelfRef.tb__DOT__data = 1U;
    vlSelfRef.tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         29);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         30);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         31);
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         32);
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         33);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         34);
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         35);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         37);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         37);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         37);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         37);
    vlSelfRef.tb__DOT__done_counting = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         39);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         39);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         39);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         39);
    vlSelfRef.tb__DOT__done_counting = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         41);
    vlSelfRef.tb__DOT__done_counting = 0U;
    vlSelfRef.tb__DOT__ack = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         44);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         44);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         44);
    vlSelfRef.tb__DOT__ack = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         46);
    vlSelfRef.tb__DOT__ack = 0U;
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         49);
    vlSelfRef.tb__DOT__ack = 0U;
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         52);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         54);
    vlSelfRef.tb__DOT__data = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         56);
    vlSelfRef.tb__DOT__data = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         58);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         58);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         58);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         58);
    vlSelfRef.tb__DOT__done_counting = 0U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         60);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         60);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         60);
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         60);
    vlSelfRef.tb__DOT__done_counting = 1U;
    co_await vlSelfRef.__VtrigSched_h13ba9e12__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb.clk)", 
                                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                         62);
    if (VL_UNLIKELY((vlSelfRef.tb__DOT__stim1__DOT__failed))) {
        VL_WRITEF_NX("Hint: Your FSM didn't pass the sample timing diagram posted with the problem statement. Perhaps try debugging that?\n",0);
    }
    tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0x1388U;
    while (VL_LTS_III(32, 0U, tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5)) {
        co_await vlSelfRef.__VtrigSched_h13ba9e51__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(edge tb.clk)", 
                                                             "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                                             69);
        vlSelfRef.tb__DOT__reset = (1U & (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xffU 
                                                      & VL_RANDOM_I())))));
        vlSelfRef.tb__DOT__data = (1U & VL_RANDOM_I());
        vlSelfRef.tb__DOT__done_counting = (1U & (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0x1fU 
                                                              & VL_RANDOM_I())))));
        vlSelfRef.tb__DOT__ack = (1U & (~ (IData)((0U 
                                                   != 
                                                   (0x1fU 
                                                    & VL_RANDOM_I())))));
        tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5 
            = (tb__DOT__stim1__DOT__unnamedblk1_6__DOT____Vrepeat5 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 
                                         76);
    VL_FINISH_MT("/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 76, "");
}

void VProb151_review2015_fsm_test___024root___act_comb__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf);

void VProb151_review2015_fsm_test___024root___eval_act(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_act\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((7ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___act_comb__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*3:0*/, 128> VProb151_review2015_fsm_test__ConstPool__TABLE_hd9150080_0;
extern const VlUnpacked<CData/*2:0*/, 256> VProb151_review2015_fsm_test__ConstPool__TABLE_hd195564b_0;

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___act_comb__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___act_comb__TOP__0\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
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
}

void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__1(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___nba_comb__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__2(VProb151_review2015_fsm_test___024root* vlSelf);
void VProb151_review2015_fsm_test___024root___nba_comb__TOP__1(VProb151_review2015_fsm_test___024root* vlSelf);

void VProb151_review2015_fsm_test___024root___eval_nba(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_nba\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VProb151_review2015_fsm_test___024root___nba_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___nba_sequent__TOP__0\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter;
    __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter = 0;
    // Body
    __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter 
        = vlSelfRef.tb__DOT__top_module1__DOT__shift_cycle_counter;
    if (vlSelfRef.tb__DOT__reset) {
        __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter = 0U;
        vlSelfRef.tb__DOT__good1__DOT__state = 0U;
    } else {
        if (((4U == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__next_state)) 
             & (4U != (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)))) {
            __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter = 0U;
        } else if ((4U == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state))) {
            __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__top_module1__DOT__shift_cycle_counter)));
        }
        vlSelfRef.tb__DOT__good1__DOT__state = vlSelfRef.tb__DOT__good1__DOT__next;
    }
    vlSelfRef.tb__DOT__top_module1__DOT__shift_cycle_counter 
        = __Vdly__tb__DOT__top_module1__DOT__shift_cycle_counter;
}

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__1(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___nba_sequent__TOP__1\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__tb__DOT__stim1__DOT__failed;
    __Vdly__tb__DOT__stim1__DOT__failed = 0;
    CData/*0:0*/ __VdlyMask__tb__DOT__stim1__DOT__failed;
    __VdlyMask__tb__DOT__stim1__DOT__failed = 0;
    // Body
    vlSelfRef.tb__DOT__stats1__BRA__31__03a0__KET__ 
        = ((IData)(1U) + vlSelfRef.tb__DOT__stats1__BRA__31__03a0__KET__);
    if ((1U & (~ (IData)(vlSelfRef.tb__DOT__tb_match)))) {
        vlSelfRef.tb__DOT__stats1__BRA__287__03a256__KET__ 
            = ((IData)(1U) + vlSelfRef.tb__DOT__stats1__BRA__287__03a256__KET__);
        __Vdly__tb__DOT__stim1__DOT__failed = 1U;
        __VdlyMask__tb__DOT__stim1__DOT__failed = 1U;
    }
    if (((IData)(vlSelfRef.tb__DOT__shift_ena_ref) 
         != (4U == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)))) {
        if ((0U == vlSelfRef.tb__DOT__stats1__BRA__223__03a192__KET__)) {
            vlSelfRef.tb__DOT__stats1__BRA__191__03a160__KET__ 
                = (IData)(VL_TIME_UNITED_Q(1));
        }
        vlSelfRef.tb__DOT__stats1__BRA__223__03a192__KET__ 
            = ((IData)(1U) + vlSelfRef.tb__DOT__stats1__BRA__223__03a192__KET__);
    }
    if (((IData)(vlSelfRef.tb__DOT__counting_ref) != 
         (5U == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)))) {
        if ((0U == vlSelfRef.tb__DOT__stats1__BRA__159__03a128__KET__)) {
            vlSelfRef.tb__DOT__stats1__BRA__127__03a96__KET__ 
                = (IData)(VL_TIME_UNITED_Q(1));
        }
        vlSelfRef.tb__DOT__stats1__BRA__159__03a128__KET__ 
            = ((IData)(1U) + vlSelfRef.tb__DOT__stats1__BRA__159__03a128__KET__);
    }
    if (((IData)(vlSelfRef.tb__DOT__done_ref) != (6U 
                                                  == (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)))) {
        if ((0U == vlSelfRef.tb__DOT__stats1__BRA__95__03a64__KET__)) {
            vlSelfRef.tb__DOT__stats1__BRA__63__03a32__KET__ 
                = (IData)(VL_TIME_UNITED_Q(1));
        }
        vlSelfRef.tb__DOT__stats1__BRA__95__03a64__KET__ 
            = ((IData)(1U) + vlSelfRef.tb__DOT__stats1__BRA__95__03a64__KET__);
    }
    vlSelfRef.tb__DOT__stim1__DOT__failed = (((IData)(__Vdly__tb__DOT__stim1__DOT__failed) 
                                              & (IData)(__VdlyMask__tb__DOT__stim1__DOT__failed)) 
                                             | ((IData)(vlSelfRef.tb__DOT__stim1__DOT__failed) 
                                                & (~ (IData)(__VdlyMask__tb__DOT__stim1__DOT__failed))));
    __VdlyMask__tb__DOT__stim1__DOT__failed = 0U;
}

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___nba_comb__TOP__0(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___nba_comb__TOP__0\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.tb__DOT__data) 
                     << 6U) | (((IData)(vlSelfRef.tb__DOT__done_counting) 
                                << 5U) | (((IData)(vlSelfRef.tb__DOT__ack) 
                                           << 4U) | (IData)(vlSelfRef.tb__DOT__good1__DOT__state))));
    vlSelfRef.tb__DOT__good1__DOT__next = VProb151_review2015_fsm_test__ConstPool__TABLE_hd9150080_0
        [__Vtableidx1];
}

extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_h245db906_0;
extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_hc6261a48_0;
extern const VlUnpacked<CData/*0:0*/, 16> VProb151_review2015_fsm_test__ConstPool__TABLE_hc5e0ab2b_0;

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___nba_sequent__TOP__2(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___nba_sequent__TOP__2\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ tb__DOT____VdfgRegularize_hf3db91df_0_0;
    tb__DOT____VdfgRegularize_hf3db91df_0_0 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
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
    vlSelfRef.tb__DOT__top_module1__DOT__current_state 
        = ((IData)(vlSelfRef.tb__DOT__reset) ? 0U : (IData)(vlSelfRef.tb__DOT__top_module1__DOT__next_state));
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

VL_INLINE_OPT void VProb151_review2015_fsm_test___024root___nba_comb__TOP__1(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___nba_comb__TOP__1\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx3 = ((((IData)(vlSelfRef.tb__DOT__data) 
                      << 7U) | (((IData)(vlSelfRef.tb__DOT__top_module1__DOT__shift_cycle_counter) 
                                 << 5U) | ((IData)(vlSelfRef.tb__DOT__done_counting) 
                                           << 4U))) 
                    | (((IData)(vlSelfRef.tb__DOT__ack) 
                        << 3U) | (IData)(vlSelfRef.tb__DOT__top_module1__DOT__current_state)));
    vlSelfRef.tb__DOT__top_module1__DOT__next_state 
        = VProb151_review2015_fsm_test__ConstPool__TABLE_hd195564b_0
        [__Vtableidx3];
}

void VProb151_review2015_fsm_test___024root___timing_commit(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___timing_commit\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h13ba9e12__0.commit(
                                                   "@(posedge tb.clk)");
    }
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h13ba9e51__0.commit(
                                                   "@(edge tb.clk)");
    }
}

void VProb151_review2015_fsm_test___024root___timing_resume(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___timing_resume\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h13ba9e12__0.resume(
                                                   "@(posedge tb.clk)");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h13ba9e51__0.resume(
                                                   "@(edge tb.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void VProb151_review2015_fsm_test___024root___eval_triggers__act(VProb151_review2015_fsm_test___024root* vlSelf);

bool VProb151_review2015_fsm_test___024root___eval_phase__act(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_phase__act\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VProb151_review2015_fsm_test___024root___eval_triggers__act(vlSelf);
    VProb151_review2015_fsm_test___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VProb151_review2015_fsm_test___024root___timing_resume(vlSelf);
        VProb151_review2015_fsm_test___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VProb151_review2015_fsm_test___024root___eval_phase__nba(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_phase__nba\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VProb151_review2015_fsm_test___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__nba(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VProb151_review2015_fsm_test___024root___dump_triggers__act(VProb151_review2015_fsm_test___024root* vlSelf);
#endif  // VL_DEBUG

void VProb151_review2015_fsm_test___024root___eval(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VProb151_review2015_fsm_test___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 81, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VProb151_review2015_fsm_test___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/Obi-wan/Documents/veridev/verilog-eval/dataset_spec-to-rtl/Prob151_review2015_fsm_test.sv", 81, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VProb151_review2015_fsm_test___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VProb151_review2015_fsm_test___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VProb151_review2015_fsm_test___024root___eval_debug_assertions(VProb151_review2015_fsm_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VProb151_review2015_fsm_test___024root___eval_debug_assertions\n"); );
    VProb151_review2015_fsm_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
