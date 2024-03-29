#pragma once

#include <instruction/instruction.h>
#include <emulator/emulator.h>
#include <instruction/instruction_impl.h>

#define NONE_ARG {ARG_NONE, 0x00}
#define REG_ARG(X) {ARG_REG, REG_##X}
#define CONST_ARG(X) {ARG_CONST, X}
#define IMM16_ARG(X) {ARG_IMM16, X}
#define IMM8_ARG(X)  {ARG_IMM8, X}

#define NONE_NONE_ARG {NONE_ARG, NONE_ARG}, 1, {}
#define REG_NONE_ARG(X) {REG_ARG(X), NONE_ARG}, 1, {}
#define REG_IMM16_ARG(X, Y) {REG_ARG(X), IMM16_ARG(Y)}, 3, {}
#define REG_IMM8_ARG(X, Y)  {REG_ARG(X), IMM8_ARG(Y)}, 2, {}
#define REG_REG_ARG(X, Y) {REG_ARG(X), REG_ARG(Y)}, 1, {}
#define CONST_NONE_ARG(X) {CONST_ARG(X), NONE_ARG}, 1, {}
#define IMM16_NONE_ARG(X) {IMM16_ARG(X), NONE_ARG}, 3, {}
#define IMM8_NONE_ARG(X) {IMM8_ARG(X), NONE_ARG}, 2, {}

const static ins_t ins_formats[] = {
    {0x00, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x01, MNEM_LXI,  REG_IMM16_ARG(B, 0x00),     execute_LXI,  10},
    {0x02, MNEM_STAX, REG_NONE_ARG(B),            execute_STAX, 7},
    {0x03, MNEM_INX,  REG_NONE_ARG(B),            execute_INX,  5},
    {0x04, MNEM_INR,  REG_NONE_ARG(B),            execute_INR,  5},
    {0x05, MNEM_DCR,  REG_NONE_ARG(B),            execute_DCR,  5},
    {0x06, MNEM_MVI,  REG_IMM8_ARG(B, 0x00),      execute_MVI,  7},
    {0x07, MNEM_RLC,  NONE_NONE_ARG,              execute_RLC,  4},
    {0x08, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x09, MNEM_DAD,  REG_NONE_ARG(B),            execute_DAD,  10},
    {0x0a, MNEM_LDAX, REG_NONE_ARG(B),            execute_LDAX, 7},
    {0x0b, MNEM_DCX,  REG_NONE_ARG(B),            execute_DCX,  5},
    {0x0c, MNEM_INR,  REG_NONE_ARG(C),            execute_INR,  5},
    {0x0d, MNEM_DCR,  REG_NONE_ARG(C),            execute_DCR,  5},
    {0x0e, MNEM_MVI,  REG_IMM8_ARG(C, 0x00),      execute_MVI,  7},
    {0x0f, MNEM_RRC,  NONE_NONE_ARG,              execute_RRC,  4},

    {0x10, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x11, MNEM_LXI,  REG_IMM16_ARG(D, 0x00),     execute_LXI,  10},
    {0x12, MNEM_STAX, REG_NONE_ARG(D),            execute_STAX, 7},
    {0x13, MNEM_INX,  REG_NONE_ARG(D),            execute_INX,  5},
    {0x14, MNEM_INR,  REG_NONE_ARG(D),            execute_INR,  5},
    {0x15, MNEM_DCR,  REG_NONE_ARG(D),            execute_DCR,  5},
    {0x16, MNEM_MVI,  REG_IMM8_ARG(D, 0x00),      execute_MVI,  7},
    {0x17, MNEM_RAL,  NONE_NONE_ARG,              execute_RAL,  4},
    {0x18, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x19, MNEM_DAD,  REG_NONE_ARG(D),            execute_DAD,  10},
    {0x1a, MNEM_LDAX, REG_NONE_ARG(D),            execute_LDAX, 7},
    {0x1b, MNEM_DCX,  REG_NONE_ARG(D),            execute_DCX,  5},
    {0x1c, MNEM_INR,  REG_NONE_ARG(E),            execute_INR,  5},
    {0x1d, MNEM_DCR,  REG_NONE_ARG(E),            execute_DCR,  5},
    {0x1e, MNEM_MVI,  REG_IMM8_ARG(E, 0x00),      execute_MVI,  7},
    {0x1f, MNEM_RAR,  NONE_NONE_ARG,              execute_RAR,  4},
    
    
    {0x20, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x21, MNEM_LXI,  REG_IMM16_ARG(H, 0x00),     execute_LXI,  10},
    {0x22, MNEM_SHLD, IMM16_NONE_ARG(0x00),       execute_SHLD, 16},
    {0x23, MNEM_INX,  REG_NONE_ARG(H),            execute_INX,  5},
    {0x24, MNEM_INR,  REG_NONE_ARG(H),            execute_INR,  5},
    {0x25, MNEM_DCR,  REG_NONE_ARG(H),            execute_DCR,  5},
    {0x26, MNEM_MVI,  REG_IMM8_ARG(H, 0x00),      execute_MVI,  7},
    {0x27, MNEM_DAA,  NONE_NONE_ARG,              execute_DAA,  4},
    {0x28, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x29, MNEM_DAD,  REG_NONE_ARG(H),            execute_DAA,  10},
    {0x2a, MNEM_LHLD, IMM16_NONE_ARG(0x00),       execute_LHLD, 16},
    {0x2b, MNEM_DCX,  REG_NONE_ARG(H),            execute_DCX,  5},
    {0x2c, MNEM_INR,  REG_NONE_ARG(L),            execute_INR,  5},
    {0x2d, MNEM_DCR,  REG_NONE_ARG(L),            execute_DCR,  5},
    {0x2e, MNEM_MVI,  REG_IMM8_ARG(L, 0x00),      execute_MVI,  7},
    {0x2f, MNEM_CMA,  NONE_NONE_ARG,              execute_CMA,  4},

    {0x30, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x31, MNEM_LXI,  REG_IMM16_ARG(SP, 0x00),    execute_LXI,  10},
    {0x32, MNEM_STA,  IMM16_NONE_ARG(0x00),       execute_STA,  13},
    {0x33, MNEM_INX,  REG_NONE_ARG(SP),           execute_INX,  5},
    {0x34, MNEM_INR,  REG_NONE_ARG(M),            execute_INR,  10},
    {0x35, MNEM_DCR,  REG_NONE_ARG(M),            execute_DCR,  10},
    {0x36, MNEM_MVI,  REG_IMM8_ARG(M, 0x00),      execute_MVI,  10},
    {0x37, MNEM_STC,  NONE_NONE_ARG,              execute_STC,  4},
    {0x38, MNEM_NOP,  NONE_NONE_ARG,              execute_NOP,  4},
    {0x33, MNEM_DAD,  REG_NONE_ARG(SP),           execute_DAD,  10},
    {0x3a, MNEM_LDA,  IMM16_NONE_ARG(0x00),       execute_LDA,  13},
    {0x3b, MNEM_DCX,  REG_NONE_ARG(SP),           execute_DCX,  5},
    {0x3c, MNEM_INR,  REG_NONE_ARG(A),            execute_INR,  5},
    {0x3d, MNEM_DCR,  REG_NONE_ARG(A),            execute_DCR,  5},
    {0x3e, MNEM_MVI,  REG_IMM8_ARG(A, 0x00),      execute_MVI,  7},
    {0x3f, MNEM_CMC,  NONE_NONE_ARG,              execute_CMC,  4},
    
 
    {0x40, MNEM_MOV,  REG_REG_ARG(B, B),          execute_MOV,  5},
    {0x41, MNEM_MOV,  REG_REG_ARG(B, C),          execute_MOV,  5},
    {0x42, MNEM_MOV,  REG_REG_ARG(B, D),          execute_MOV,  5},
    {0x43, MNEM_MOV,  REG_REG_ARG(B, E),          execute_MOV,  5},
    {0x44, MNEM_MOV,  REG_REG_ARG(B, H),          execute_MOV,  5},
    {0x45, MNEM_MOV,  REG_REG_ARG(B, L),          execute_MOV,  5},
    {0x46, MNEM_MOV,  REG_REG_ARG(B, M),          execute_MOV,  7},
    {0x47, MNEM_MOV,  REG_REG_ARG(B, A),          execute_MOV,  5},
    {0x48, MNEM_MOV,  REG_REG_ARG(C, B),          execute_MOV,  5},
    {0x49, MNEM_MOV,  REG_REG_ARG(C, C),          execute_MOV,  5},
    {0x4a, MNEM_MOV,  REG_REG_ARG(C, D),          execute_MOV,  5},
    {0x4b, MNEM_MOV,  REG_REG_ARG(C, E),          execute_MOV,  5},
    {0x4c, MNEM_MOV,  REG_REG_ARG(C, H),          execute_MOV,  5},
    {0x4d, MNEM_MOV,  REG_REG_ARG(C, L),          execute_MOV,  5},
    {0x4e, MNEM_MOV,  REG_REG_ARG(C, M),          execute_MOV,  7},
    {0x4f, MNEM_MOV,  REG_REG_ARG(C, A),          execute_MOV,  5},
    
    {0x50, MNEM_MOV,  REG_REG_ARG(D, B),          execute_MOV,  5},
    {0x51, MNEM_MOV,  REG_REG_ARG(D, C),          execute_MOV,  5},
    {0x52, MNEM_MOV,  REG_REG_ARG(D, D),          execute_MOV,  5},
    {0x53, MNEM_MOV,  REG_REG_ARG(D, E),          execute_MOV,  5},
    {0x54, MNEM_MOV,  REG_REG_ARG(D, H),          execute_MOV,  5},
    {0x55, MNEM_MOV,  REG_REG_ARG(D, L),          execute_MOV,  5},
    {0x56, MNEM_MOV,  REG_REG_ARG(D, M),          execute_MOV,  7},
    {0x57, MNEM_MOV,  REG_REG_ARG(D, A),          execute_MOV,  5},
    {0x58, MNEM_MOV,  REG_REG_ARG(E, B),          execute_MOV,  5},
    {0x59, MNEM_MOV,  REG_REG_ARG(E, C),          execute_MOV,  5},
    {0x5a, MNEM_MOV,  REG_REG_ARG(E, D),          execute_MOV,  5},
    {0x5b, MNEM_MOV,  REG_REG_ARG(E, E),          execute_MOV,  5},
    {0x5c, MNEM_MOV,  REG_REG_ARG(E, H),          execute_MOV,  5},
    {0x5d, MNEM_MOV,  REG_REG_ARG(E, L),          execute_MOV,  5},
    {0x5e, MNEM_MOV,  REG_REG_ARG(E, M),          execute_MOV,  7},
    {0x5f, MNEM_MOV,  REG_REG_ARG(E, A),          execute_MOV,  5},
     
    {0x60, MNEM_MOV,  REG_REG_ARG(H, B),          execute_MOV,  5},
    {0x61, MNEM_MOV,  REG_REG_ARG(H, C),          execute_MOV,  5},
    {0x62, MNEM_MOV,  REG_REG_ARG(H, D),          execute_MOV,  5},
    {0x63, MNEM_MOV,  REG_REG_ARG(H, E),          execute_MOV,  5},
    {0x64, MNEM_MOV,  REG_REG_ARG(H, H),          execute_MOV,  5},
    {0x65, MNEM_MOV,  REG_REG_ARG(H, L),          execute_MOV,  5},
    {0x66, MNEM_MOV,  REG_REG_ARG(H, M),          execute_MOV,  7},
    {0x67, MNEM_MOV,  REG_REG_ARG(H, A),          execute_MOV,  5},
    {0x68, MNEM_MOV,  REG_REG_ARG(H, B),          execute_MOV,  5},
    {0x69, MNEM_MOV,  REG_REG_ARG(L, C),          execute_MOV,  5},
    {0x6a, MNEM_MOV,  REG_REG_ARG(L, D),          execute_MOV,  5},
    {0x6b, MNEM_MOV,  REG_REG_ARG(L, E),          execute_MOV,  5},
    {0x6c, MNEM_MOV,  REG_REG_ARG(L, H),          execute_MOV,  5},
    {0x6d, MNEM_MOV,  REG_REG_ARG(L, L),          execute_MOV,  5},
    {0x6e, MNEM_MOV,  REG_REG_ARG(L, M),          execute_MOV,  7},
    {0x6f, MNEM_MOV,  REG_REG_ARG(L, A),          execute_MOV,  5},

    {0x70, MNEM_MOV,  REG_REG_ARG(M, B),          execute_MOV,  7},
    {0x71, MNEM_MOV,  REG_REG_ARG(M, C),          execute_MOV,  7},
    {0x72, MNEM_MOV,  REG_REG_ARG(M, D),          execute_MOV,  7},
    {0x73, MNEM_MOV,  REG_REG_ARG(M, E),          execute_MOV,  7},
    {0x74, MNEM_MOV,  REG_REG_ARG(M, H),          execute_MOV,  7},
    {0x75, MNEM_MOV,  REG_REG_ARG(M, L),          execute_MOV,  7},
    {0x76, MNEM_HLT,  NONE_NONE_ARG,              execute_HLT,  7},
    {0x77, MNEM_MOV,  REG_REG_ARG(M, A),          execute_MOV,  7},
    {0x78, MNEM_MOV,  REG_REG_ARG(A, B),          execute_MOV,  5},
    {0x79, MNEM_MOV,  REG_REG_ARG(A, C),          execute_MOV,  5},
    {0x7a, MNEM_MOV,  REG_REG_ARG(A, D),          execute_MOV,  5},
    {0x7b, MNEM_MOV,  REG_REG_ARG(A, E),          execute_MOV,  5},
    {0x7c, MNEM_MOV,  REG_REG_ARG(A, H),          execute_MOV,  5},
    {0x7d, MNEM_MOV,  REG_REG_ARG(A, L),          execute_MOV,  5},
    {0x7e, MNEM_MOV,  REG_REG_ARG(A, M),          execute_MOV,  7},
    {0x7f, MNEM_MOV,  REG_REG_ARG(A, A),          execute_MOV,  5},

    {0x80, MNEM_ADD, REG_NONE_ARG(B),             execute_ADD,  4},
    {0x81, MNEM_ADD, REG_NONE_ARG(C),             execute_ADD,  4},
    {0x82, MNEM_ADD, REG_NONE_ARG(D),             execute_ADD,  4},
    {0x83, MNEM_ADD, REG_NONE_ARG(E),             execute_ADD,  4},
    {0x84, MNEM_ADD, REG_NONE_ARG(H),             execute_ADD,  4},
    {0x85, MNEM_ADD, REG_NONE_ARG(L),             execute_ADD,  4},
    {0x86, MNEM_ADD, REG_NONE_ARG(M),             execute_ADD,  7},
    {0x87, MNEM_ADD, REG_NONE_ARG(A),             execute_ADD,  4},
    {0x88, MNEM_ADC, REG_NONE_ARG(B),             execute_ADC,  4},
    {0x89, MNEM_ADC, REG_NONE_ARG(C),             execute_ADC,  4},
    {0x8a, MNEM_ADC, REG_NONE_ARG(D),             execute_ADC,  4},
    {0x8b, MNEM_ADC, REG_NONE_ARG(E),             execute_ADC,  4},
    {0x8c, MNEM_ADC, REG_NONE_ARG(H),             execute_ADC,  4},
    {0x8d, MNEM_ADC, REG_NONE_ARG(L),             execute_ADC,  4},
    {0x8e, MNEM_ADC, REG_NONE_ARG(M),             execute_ADC,  7},
    {0x8f, MNEM_ADC, REG_NONE_ARG(A),             execute_ADC,  4},
     
    {0x90, MNEM_SUB, REG_NONE_ARG(B),             execute_SUB,  4},
    {0x91, MNEM_SUB, REG_NONE_ARG(C),             execute_SUB,  4},
    {0x92, MNEM_SUB, REG_NONE_ARG(D),             execute_SUB,  4},
    {0x93, MNEM_SUB, REG_NONE_ARG(E),             execute_SUB,  4},
    {0x94, MNEM_SUB, REG_NONE_ARG(H),             execute_SUB,  4},
    {0x95, MNEM_SUB, REG_NONE_ARG(L),             execute_SUB,  4},
    {0x96, MNEM_SUB, REG_NONE_ARG(M),             execute_SUB,  7},
    {0x97, MNEM_SUB, REG_NONE_ARG(A),             execute_SUB,  4},
    {0x98, MNEM_SBB, REG_NONE_ARG(B),             execute_SBB,  4},
    {0x99, MNEM_SBB, REG_NONE_ARG(C),             execute_SBB,  4},
    {0x9a, MNEM_SBB, REG_NONE_ARG(D),             execute_SBB,  4},
    {0x9b, MNEM_SBB, REG_NONE_ARG(E),             execute_SBB,  4},
    {0x9c, MNEM_SBB, REG_NONE_ARG(H),             execute_SBB,  4},
    {0x9d, MNEM_SBB, REG_NONE_ARG(L),             execute_SBB,  4},
    {0x9e, MNEM_SBB, REG_NONE_ARG(M),             execute_SBB,  7},
    {0x9f, MNEM_SBB, REG_NONE_ARG(A),             execute_SBB,  4},
    
    {0xa0, MNEM_ANA, REG_NONE_ARG(B),             execute_ANA,  4},
    {0xa1, MNEM_ANA, REG_NONE_ARG(C),             execute_ANA,  4},
    {0xa2, MNEM_ANA, REG_NONE_ARG(D),             execute_ANA,  4},
    {0xa3, MNEM_ANA, REG_NONE_ARG(E),             execute_ANA,  4},
    {0xa4, MNEM_ANA, REG_NONE_ARG(H),             execute_ANA,  4},
    {0xa5, MNEM_ANA, REG_NONE_ARG(L),             execute_ANA,  4},
    {0xa6, MNEM_ANA, REG_NONE_ARG(M),             execute_ANA,  7},
    {0xa7, MNEM_ANA, REG_NONE_ARG(A),             execute_ANA,  4},
    {0xa8, MNEM_XRA, REG_NONE_ARG(B),             execute_XRA,  4},
    {0xa9, MNEM_XRA, REG_NONE_ARG(C),             execute_XRA,  4},
    {0xaa, MNEM_XRA, REG_NONE_ARG(D),             execute_XRA,  4},
    {0xab, MNEM_XRA, REG_NONE_ARG(E),             execute_XRA,  4},
    {0xac, MNEM_XRA, REG_NONE_ARG(H),             execute_XRA,  4},
    {0xad, MNEM_XRA, REG_NONE_ARG(L),             execute_XRA,  4},
    {0xae, MNEM_XRA, REG_NONE_ARG(M),             execute_XRA,  7},
    {0xaf, MNEM_XRA, REG_NONE_ARG(A),             execute_XRA,  4},
    
    {0xb0, MNEM_ORA, REG_NONE_ARG(B),             execute_ORA,  4},
    {0xb1, MNEM_ORA, REG_NONE_ARG(C),             execute_ORA,  4},
    {0xb2, MNEM_ORA, REG_NONE_ARG(D),             execute_ORA,  4},
    {0xb3, MNEM_ORA, REG_NONE_ARG(E),             execute_ORA,  4},
    {0xb4, MNEM_ORA, REG_NONE_ARG(H),             execute_ORA,  4},
    {0xb5, MNEM_ORA, REG_NONE_ARG(L),             execute_ORA,  4},
    {0xb6, MNEM_ORA, REG_NONE_ARG(M),             execute_ORA,  7},
    {0xb7, MNEM_ORA, REG_NONE_ARG(A),             execute_ORA,  4},
    {0xb8, MNEM_CMP, REG_NONE_ARG(B),             execute_CMP,  4},
    {0xb9, MNEM_CMP, REG_NONE_ARG(C),             execute_CMP,  4},
    {0xba, MNEM_CMP, REG_NONE_ARG(D),             execute_CMP,  4},
    {0xbb, MNEM_CMP, REG_NONE_ARG(E),             execute_CMP,  4},
    {0xbc, MNEM_CMP, REG_NONE_ARG(H),             execute_CMP,  4},
    {0xbd, MNEM_CMP, REG_NONE_ARG(L),             execute_CMP,  4},
    {0xbe, MNEM_CMP, REG_NONE_ARG(M),             execute_CMP,  7},
    {0xbf, MNEM_CMP, REG_NONE_ARG(A),             execute_CMP,  4},
    
    
    {0xc0, MNEM_RNZ, NONE_NONE_ARG,               execute_RNZ,  5},
    {0xc1, MNEM_POP, REG_NONE_ARG(B),             execute_POP,  10},
    {0xc2, MNEM_JNZ, IMM16_NONE_ARG(0x00),        execute_JNZ,  10},
    {0xc3, MNEM_JMP, IMM16_NONE_ARG(0x00),        execute_JMP,  10},
    {0xc4, MNEM_CNZ, IMM16_NONE_ARG(0x00),        execute_CNZ,  11},
    {0xc5, MNEM_PUSH, REG_NONE_ARG(B),            execute_PUSH, 11},
    {0xc6, MNEM_ADI, IMM8_NONE_ARG(0x00),         execute_ADI,  7},
    {0xc7, MNEM_RST, CONST_NONE_ARG(0),           execute_RST,  11},
    {0xc8, MNEM_RZ, NONE_NONE_ARG,                execute_RZ,   5},
    {0xc9, MNEM_RET, NONE_NONE_ARG,               execute_RET,  10},
    {0xca, MNEM_JZ, IMM16_NONE_ARG(0x00),         execute_JZ,   10},
    {0xcb, MNEM_JMP, IMM16_NONE_ARG(0x00),        execute_JMP,  10},
    {0xcc, MNEM_CZ,  IMM16_NONE_ARG(0x00),        execute_CZ,   11},
    {0xcd, MNEM_CALL, IMM16_NONE_ARG(0x00),       execute_CALL, 17},
    {0xce, MNEM_ACI,  IMM8_NONE_ARG(0x00),        execute_ACI,  7},
    {0xcf, MNEM_RST, CONST_NONE_ARG(1),           execute_RST,  11},

    {0xd0, MNEM_RNC, NONE_NONE_ARG,               execute_RNC,  5},
    {0xd1, MNEM_POP, REG_NONE_ARG(D),             execute_POP,  10},
    {0xd2, MNEM_JNC, IMM16_NONE_ARG(0x00),        execute_JNC,  10},
    {0xd3, MNEM_OUT, IMM8_NONE_ARG(0x00),         execute_OUT,  10},
    {0xd4, MNEM_CNC, IMM16_NONE_ARG(0x00),        execute_CNC,  11},
    {0xd5, MNEM_PUSH, REG_NONE_ARG(D),            execute_PUSH, 11},
    {0xd6, MNEM_SUI, IMM8_NONE_ARG(0x00),         execute_SUI,  7},
    {0xd7, MNEM_RST, CONST_NONE_ARG(2),           execute_RST,  11},
    {0xd8, MNEM_RC, NONE_NONE_ARG,                execute_RC,   5},
    {0xd9, MNEM_RET, NONE_NONE_ARG,               execute_RET,  10},
    {0xda, MNEM_JC, IMM16_NONE_ARG(0x00),         execute_JC,   10},
    {0xdb, MNEM_IN, IMM8_NONE_ARG(0x00),          execute_IN,   10},
    {0xdc, MNEM_CC,  IMM16_NONE_ARG(0x00),        execute_CC,   11},
    {0xdd, MNEM_CALL, IMM16_NONE_ARG(0x00),       execute_CALL, 17},
    {0xde, MNEM_SBI,  IMM8_NONE_ARG(0x00),        execute_SBI,  7},
    {0xdf, MNEM_RST, CONST_NONE_ARG(3),           execute_RST,  11},

    {0xe0, MNEM_RPO, NONE_NONE_ARG,               execute_RPO,  5},
    {0xe1, MNEM_POP, REG_NONE_ARG(H),             execute_POP,  10},
    {0xe2, MNEM_JPO, IMM16_NONE_ARG(0x00),        execute_JPO,  10},
    {0xe3, MNEM_XTHL, NONE_NONE_ARG,              execute_XTHL, 18},
    {0xe4, MNEM_CPO, IMM16_NONE_ARG(0x00),        execute_CPO,  11},
    {0xe5, MNEM_PUSH, REG_NONE_ARG(H),            execute_PUSH, 11},
    {0xe6, MNEM_ANI, IMM8_NONE_ARG(0x00),         execute_ANI,  7},
    {0xe7, MNEM_RST, CONST_NONE_ARG(4),           execute_RST,  11},
    {0xe8, MNEM_RPE, NONE_NONE_ARG,               execute_RPE,  5},
    {0xe9, MNEM_PCHL, NONE_NONE_ARG,              execute_PCHL, 5},
    {0xea, MNEM_JPE, IMM16_NONE_ARG(0x00),        execute_JPE,  10},
    {0xeb, MNEM_XCHG, NONE_NONE_ARG,              execute_XCHG, 5},
    {0xec, MNEM_CPE,  IMM16_NONE_ARG(0x00),       execute_CPE,  11},
    {0xed, MNEM_CALL, IMM16_NONE_ARG(0x00),       execute_CALL, 17},
    {0xee, MNEM_XRI,  IMM8_NONE_ARG(0x00),        execute_XRI,  7},
    {0xef, MNEM_RST, CONST_NONE_ARG(5),           execute_RST,  11},

    {0xf0, MNEM_RP, NONE_NONE_ARG,                execute_RP,   5},
    {0xf1, MNEM_POP, REG_NONE_ARG(PSW),           execute_POP,  10},
    {0xf2, MNEM_JP, IMM16_NONE_ARG(0x00),         execute_JP,   10},
    {0xf3, MNEM_DI, NONE_NONE_ARG,                execute_DI,   4},
    {0xf4, MNEM_CP, IMM16_NONE_ARG(0x00),         execute_CP,   11},
    {0xf5, MNEM_PUSH, REG_NONE_ARG(PSW),          execute_PUSH, 11},
    {0xf6, MNEM_ORI, IMM8_NONE_ARG(0x00),         execute_ORI,  7},
    {0xf7, MNEM_RST, CONST_NONE_ARG(6),           execute_RST,  11},
    {0xf8, MNEM_RM, NONE_NONE_ARG,                execute_RM,   5},
    {0xf9, MNEM_SPHL, NONE_NONE_ARG,              execute_SPHL, 5},
    {0xfa, MNEM_JM, IMM16_NONE_ARG(0x00),         execute_JM,   10},
    {0xfb, MNEM_EI, NONE_NONE_ARG,                execute_EI,   4},
    {0xfc, MNEM_CM,  IMM16_NONE_ARG(0x00),        execute_CM,   11},
    {0xfd, MNEM_CALL, IMM16_NONE_ARG(0x00),       execute_CALL, 17},
    {0xfe, MNEM_CPI,  IMM8_NONE_ARG(0x00),        execute_CPI,  7},
    {0xff, MNEM_RST, CONST_NONE_ARG(7),           execute_RST,  11},

};
