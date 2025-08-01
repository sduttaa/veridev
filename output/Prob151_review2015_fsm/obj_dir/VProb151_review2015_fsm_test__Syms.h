// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPROB151_REVIEW2015_FSM_TEST__SYMS_H_
#define VERILATED_VPROB151_REVIEW2015_FSM_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VProb151_review2015_fsm_test.h"

// INCLUDE MODULE CLASSES
#include "VProb151_review2015_fsm_test___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VProb151_review2015_fsm_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VProb151_review2015_fsm_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VProb151_review2015_fsm_test___024root TOP;

    // CONSTRUCTORS
    VProb151_review2015_fsm_test__Syms(VerilatedContext* contextp, const char* namep, VProb151_review2015_fsm_test* modelp);
    ~VProb151_review2015_fsm_test__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
