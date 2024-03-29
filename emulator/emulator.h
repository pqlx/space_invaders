#pragma once
#include <arcade.h>
#include <instruction/instruction.h>


int emulate(arcade_t *arcade);
void execute_current_ins(arcade_t *a);
uint64_t do_frame_action(arcade_t *a, uint64_t previous_time, bool midscreen);
void trigger_interrupt(arcade_t *a, size_t num);
void render_frame(bool mode);
