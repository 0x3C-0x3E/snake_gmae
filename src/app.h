#pragma once
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "renderer.h"

typedef struct {
    int terminal_width; 
    int terminal_height; 

    int elapsed_ticks;

    bool is_running;
} App;

void app_init(App* app);

void app_run(App* app);

void app_update(App* app);

void app_draw(App* app);

void app_handle_keyboard_input(App* app);
