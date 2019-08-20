#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <debug/debug.h>
#include <emulator/emulator.h>
#include <instruction/instruction.h>
#include <arcade.h>
#include <debug/debug_state.h>
#include <debug/debug_info.h>

int emulate(arcade_t *a, uint16_t *breakpoints)
{
    #define TO_USEC(ts) 1000000 * ts.tv_sec + ts.tv_nsec / 1000000
    
    struct timespec ts;
    uint64_t prev_frame_time;
    size_t bp_length = 0;

    timespec_get(&ts, TIME_UTC);
    prev_frame_time = TO_USEC(ts);
    
    if(breakpoints != NULL)
        while(breakpoints[bp_length] != 0xffff) bp_length++;
    
    a->cycles_passed = 0;

    while(true)
    {
        if(a->cycles_passed >= 33333)
            prev_frame_time = do_frame_action(a, prev_frame_time);
            
        if(a->debug_enabled)
        {
            debug_add_trace(&a->debug_state->trace_ins, a->PC);

            interactive_context(a, breakpoints, &bp_length);
        }
        
        execute_current_ins(a);    
             
    }
    return 0;
}


void execute_current_ins(arcade_t *a)
{
    ins_t instruction = {};
    uint8_t *ins_bytecode = &a->mem->mem[a->PC];

    if(a->PC > sizeof *a->mem ||
       a->SP > sizeof *a->mem)
    {
        char context_buf[2048] = {};
        puts("*** Addressing register out of bounds!! ***");
        if(a->debug_enabled)
        {
            arcade_context(a, context_buf);
            puts(context_buf);
            printf("\n\nInstruction trace:\n");
            debug_print_ins_trace(&a->debug_state->trace_ins);

            printf("\n\nFunction trace:\n");
            debug_print_label_trace(&a->debug_state->trace_label);
            puts("");
        }
        
        exit(1);
    }

    parse_ins(&instruction, ins_bytecode);
        
    if(a->debug_enabled)
    {
        const debug_label_t *label = ins_alters_pc_to_label(a, &instruction);
        
        if(label != NULL)
        {
            debug_add_trace(&a->debug_state->trace_label, label->address);
        }
    }
        
    instruction.ins_func(a, &instruction);
    
    a->PC += instruction.bytecode_size; 
    a->cycles_passed += instruction.cycle_count;
}

uint64_t do_frame_action(arcade_t *a, uint64_t previous_time)
{
    struct timespec ts; 
    timespec_get(&ts, TIME_UTC);
    int64_t delta =  TO_USEC(ts) - previous_time;
    int64_t to_sleep = 16666 - delta;
    if(to_sleep >= 0) usleep(to_sleep);
            
    timespec_get(&ts, TIME_UTC);
    previous_time = TO_USEC(ts);

    a->cycles_passed = 0;

    /* render video memory *before* interrupt */
    render_frame();

    if(a->interrupt_enabled)
        trigger_interrupt(a, 2);
    
    return previous_time;
}

void render_frame() {}


void trigger_interrupt(arcade_t *a, size_t num)
{
    if(num > 7) return;
    a->SP -= 2;
    *((uint16_t*)&a->mem->mem[a->SP]) = a->PC;
    
    a->PC = num * 8; // RST num
}
