#pragma once
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    int terminal_width; 
    int terminal_height; 

    int arena_width;
    int arena_height;

    int elapsed_ticks;
} RenderData;

void render_data_update(RenderData* render_data);

void draw_at(RenderData* render_data, int x, int y, const char* text);

void draw_text(RenderData* render_data, const char* text);

void renderer_draw_arena(RenderData* render_data);
