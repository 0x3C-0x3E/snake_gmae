#include "snake.h"

void snake_init(Snake* snake, GameContext* game_context) {
    snake->game_context = game_context;
    snake->head_x = game_context->render_data->arena_width  / 2;
    snake->head_y = game_context->render_data->arena_height / 2;
}

void snake_update(Snake* snake) {
    if (snake->game_context->inputs.up) {
        snake->head_y --;
    } else if (snake->game_context->inputs.down) {
        snake->head_y ++;
    } else if (snake->game_context->inputs.left) {
        snake->head_x --;
    } else if (snake->game_context->inputs.right) {
        snake->head_x ++;
    }
}

void snake_draw(Snake* snake) {
    draw_at(snake->game_context->render_data, snake->head_x, snake->head_y, "#");
}
