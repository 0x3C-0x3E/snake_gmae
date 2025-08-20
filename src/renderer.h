#pragma once

typedef struct {
    int terminal_width; 
    int terminal_height; 

    int elapsed_ticks;
} RenderData;

void update_render_data(RenderData* render_data);
