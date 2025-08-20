#include "app.h"
#include "config.h"
#include "renderer.h"

void app_init(App* app) {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    
    render_data_update(&app->render_data);
    app->render_data.arena_width = (app->render_data.terminal_width  < ARENA_WIDTH ) ? app->render_data.terminal_width : ARENA_WIDTH;
    app->render_data.arena_height= (app->render_data.terminal_height < ARENA_HEIGHT) ? app->render_data.terminal_height: ARENA_HEIGHT;

    app->elapsed_ticks = 0;

    app->is_running = true;
}

void app_run(App* app) {
    while (app->is_running) {
        app_handle_keyboard_input(app);

        app_update(app);

        app_draw(app);
        
        usleep(3333); // 30 FPS
    }
}

void app_update(App* app) {
    app->elapsed_ticks ++;
}

void app_draw(App* app) {
    erase();

    renderer_draw_arena(&app->render_data);

    char buff[255];
    sprintf(buff, "%d", app->elapsed_ticks);

    draw_text(&app->render_data, buff);

    refresh();
}

void app_handle_keyboard_input(App* app) {
    int ch = getch();
    if (ch == 'q') app->is_running = false;
}
