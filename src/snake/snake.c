#include "snake.h"

void snake_init(Snake* snake, GameContext* game_context) {
    snake->game_context = game_context;
    snake->head_x = game_context->render_data->arena_width  / 2;
    snake->head_y = game_context->render_data->arena_height / 2;

    snake->parts_length = 0;
    snake_add_part(snake, snake->head_x - 2, snake->head_y);
    snake_add_part(snake, snake->head_x - 1, snake->head_y);

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
    if (snake->dir == -1) {
        // this is there to prevent the snake collapsing (:
        return;
    }

    snake_add_part(snake, snake->head_x, snake->head_y);
    if (snake->head_x == snake->game_context->apple_x && snake->head_y == snake->game_context->apple_y) {
        snake->game_context->apple_x = rand_range(1, snake->game_context->render_data->arena_width  - 1);
        snake->game_context->apple_x = rand_range(1, snake->game_context->render_data->arena_height - 1);

    } else {
        snake_remove_first_part(snake);
    }


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

    if (snake->head_x <= 0) {snake->head_x = snake->game_context->render_data->arena_width  - 1;}
    if (snake->head_y <= 0) {snake->head_y = snake->game_context->render_data->arena_height - 1;}

    if (snake->head_x >= snake->game_context->render_data->arena_width ) {snake->head_x = 1;}
    if (snake->head_y >= snake->game_context->render_data->arena_height) {snake->head_y = 1;}

    for (size_t i = 0; i < snake->parts_length; i++) {
        if (snake->head_x == snake->parts[i].x && snake->head_y == snake->parts[i].y) {
            snake->game_context->gameover = true;
        }
    }
}

void snake_draw(Snake* snake) {
    for (size_t i = 0; i < snake->parts_length; i++) {
        int x = snake->parts[i].x;
        int y = snake->parts[i].y;
        draw_at(snake->game_context->render_data, x, y, "*");
    }

    draw_at(snake->game_context->render_data, snake->head_x, snake->head_y, "#");
}

void snake_add_part(Snake* snake, int x, int y) {
    snake->parts[snake->parts_length] = (SnakeBodyPart) {.x = x, .y = y};
    snake->parts_length ++;
}

void snake_remove_first_part(Snake* snake) {
    for (size_t i = 1; i < snake->parts_length; i++) {
        snake->parts[i - 1] = snake->parts[i];
    }
    snake->parts_length --;
}
