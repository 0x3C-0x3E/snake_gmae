#include "app.h"

void app_init(App* app) {
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    
    getmaxyx(stdscr, app->terminal_height, app->terminal_width);
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
    getmaxyx(stdscr, app->terminal_height, app->terminal_width);
    app->elapsed_ticks ++;
}

void app_draw(App* app) {
    erase();

    char buff[255];
    sprintf(buff, "%d", app->elapsed_ticks);

    size_t buff_len = strlen(buff);
    mvprintw(app->terminal_height/2, app->terminal_width/2 - (buff_len / 2), "%s", buff);

    refresh();
}

void app_handle_keyboard_input(App* app) {
    int ch = getch();
    if (ch == 'q') app->is_running = false;
}
