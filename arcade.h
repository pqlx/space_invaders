#pragma once
#include <stdint.h>

#include "register.h"


#pragma pack(1)
typedef struct arcade_mem {

    union {
        uint8_t mem[0x4000];
        struct {
            union {
                uint8_t ROM[0x2000];
                struct {
                    uint8_t ROM_0[0x800];
                    uint8_t ROM_1[0x800];
                    uint8_t ROM_2[0x800];
                    uint8_t ROM_3[0x800];
                };
            };  
            union {
                uint8_t RAM[0x2000];
                struct {
                    uint8_t work_RAM[0x400];
                    uint8_t video_RAM[0x1c00];
                };
            };
        };
    };   

} arcade_mem_t;


typedef struct arcade {
    
    union {
        struct {
            uint8_t A;
     
            struct {
                unsigned C:1;
                unsigned SET:1;
                unsigned P:1;
                unsigned NS_0:1;
                unsigned AC:1;
                unsigned NS_1:1;
                unsigned Z:1;
                unsigned S:1;

            } FLAGS;
        };
        uint16_t PSW;
    };

    union {
        struct {
            uint8_t B;
            uint8_t C;
        };
        uint16_t BC;
    };
    
    union {
        struct {
            uint8_t D;
            uint8_t E;
        };
        uint16_t DE;
    };
    
    union {
        struct {
            uint8_t H;
            uint8_t L;
        };
        uint16_t HL;
    };

    
    uint16_t PC;
    uint16_t SP;

    arcade_mem_t *mem;

} arcade_t;

void setup_arcade(arcade_t *arcade);
char *register_state_str(arcade_t *arcade);
