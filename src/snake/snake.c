#include "snake.h"

void snake_init(Snake* snake, GameContext* game_context) {
    snake->game_context = game_context;
    snake->head_x = game_context->render_data->arena_width  / 2;
    snake->head_y = game_context->render_data->arena_height / 2;

    snake->dir = -1;
}

void snake_update(Snake* snake) {
    if (snake->game_context->inputs.up) {
        snake->dir = DIR_UP;
    } else if (snake->game_context->inputs.down) {
        snake->dir = DIR_DOWN;
    } else if (snake->game_context->inputs.left) {
        snake->dir = DIR_LEFT;
    } else if (snake->game_context->inputs.right) {
        snake->dir = DIR_RIGHT;
    }
}

void snake_update_tick(Snake* snake) {
    switch (snake->dir) {
        case DIR_UP:
            snake->head_y --;
            break;
        case DIR_DOWN:
            snake->head_y ++;
            break;
        case DIR_LEFT:
            snake->head_x --;
            break;
        case DIR_RIGHT:
            snake->head_x ++;
            break;
    }

    if (snake->head_x <= 0) {snake->head_x = 1;}
    if (snake->head_y <= 0) {snake->head_y = 1;}

    if (snake->head_x >= snake->game_context->render_data->arena_width ) {snake->head_x = snake->game_context->render_data->arena_width  - 1;}
    if (snake->head_y >= snake->game_context->render_data->arena_height) {snake->head_y = snake->game_context->render_data->arena_height - 1;}
}

void snake_draw(Snake* snake) {
    draw_at(snake->game_context->render_data, snake->head_x, snake->head_y, "#");
}
