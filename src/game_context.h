#pragma once
#include <stdbool.h>
#include "renderer.h"

typedef struct {
    bool up; 
    bool down; 
    bool left; 
    bool right; 

    bool restart; 
    bool quit; 
} Inputs;

typedef struct {
    Inputs inputs;
    RenderData* render_data;

    int apple_x;
    int apple_y;
} GameContext;


