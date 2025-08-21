#pragma once
#include <stdbool.h>
#include "../game_context.h"

typedef enum {
    DIR_UP    = 0,
    DIR_DOWN  = 1,
    DIR_LEFT  = 2,
    DIR_RIGHT = 3,

} DIRECTIONS;

typedef struct {
    GameContext* game_context;

    int head_x, head_y;
    int dir;
} Snake;

void snake_init(Snake* snake, GameContext* game_context);

void snake_update(Snake* snake);

void snake_update_tick(Snake* snake);

void snake_draw(Snake* snake);
