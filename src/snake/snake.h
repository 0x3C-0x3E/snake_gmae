#pragma once
#include <stdbool.h>
#include "../game_context.h"

typedef struct {
    GameContext* game_context;

    int head_x, head_y;
} Snake;

void snake_init(Snake* snake, GameContext* game_context);

void snake_update(Snake* snake);

void snake_draw(Snake* snake);
