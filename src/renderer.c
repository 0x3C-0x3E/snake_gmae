#include "renderer.h"

void render_data_update(RenderData* render_data) {
    getmaxyx(stdscr, render_data->terminal_height, render_data->terminal_width);
}


void draw_at(RenderData* render_data, int x, int y, const char* text) {
    int draw_x = (render_data->arena_width >= x) ? x : render_data->arena_width;
    int draw_y = (render_data->arena_height>= y) ? y : render_data->arena_height;
    mvprintw(draw_y, draw_x, "%s", text);
}


void draw_text(RenderData* render_data, const char* text) {
    size_t buff_len = strlen(text);
    draw_at(render_data,
            render_data->arena_width / 2 - buff_len,
            render_data->arena_height/ 2,
            text);
}

void renderer_draw_arena(RenderData* render_data) {
    for (int y = 0; y < render_data->arena_height; y++) {
        char buff[render_data->arena_width];
        size_t buff_size = 0;
        
        for (int x = 0; x < render_data->arena_width; x++) {
            if (y == 0 || y == render_data->arena_height - 1) {
                buff[buff_size] = '-';
                buff_size ++;
                continue;
            }
            if (x == 0 || x == render_data->arena_width - 1) {
                buff[buff_size] = '|';
                buff_size ++;
                continue;
            }

            buff[buff_size] = ' ';
            buff_size ++;
        }

        buff[buff_size] = '\0';
        draw_at(render_data, 0, y, buff);
    }

}
