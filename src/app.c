#include "app.h"
#include "snake/snake.h"
#include <ncurses.h>

void app_init(App* app) {
    initscr();            // Start ncurses mode
    cbreak();
    keypad(stdscr, TRUE); // Enable special keys (arrows, F1, etc.)
    nodelay(stdscr, TRUE); // Non-blocking getch()
    noecho();             // Don't echo key presses
    curs_set(0);

    render_data_update(&app->render_data);
    app->render_data.arena_width = (app->render_data.terminal_width  < ARENA_WIDTH ) ? app->render_data.terminal_width : ARENA_WIDTH;
    app->render_data.arena_height= (app->render_data.terminal_height < ARENA_HEIGHT) ? app->render_data.terminal_height: ARENA_HEIGHT;

    app->game_context = (GameContext) {
        .render_data = &app->render_data,
        .inputs = {0},
        .apple_x = 3,
        .apple_y = 4,
    };

    app->elapsed_ticks = 0;

    app->is_running = true;

    snake_init(&app->snake, &app->game_context);
}

void app_run(App* app) {
    while (app->is_running) {
        app_handle_keyboard_input(app);
        if (app->is_running == false) {
            break;
        }

        app_update(app);

        app_draw(app);
        
        usleep(3333); // 30 FPS
    }
    endwin();
}

void app_update(App* app) {
    snake_update(&app->snake);
    app->elapsed_ticks ++;
}

void app_draw(App* app) {
    erase();

    renderer_draw_arena(&app->render_data);

    // char buff[255];
    // sprintf(buff, "%d", app->elapsed_ticks);
    //
    // draw_text(&app->render_data, buff);
    snake_draw(&app->snake);

    refresh();
}

void app_handle_keyboard_input(App* app) {
    int ch = getch();
    if (ch == 'q') app->is_running = false;
    app->game_context.inputs.up    = false;
    app->game_context.inputs.down  = false;
    app->game_context.inputs.left  = false;
    app->game_context.inputs.right = false;
    switch (ch) {
        case KEY_UP:
        case 'w':
        case 'k':
            app->game_context.inputs.up    = true;
            break;
        case KEY_DOWN:
        case 's':
        case 'j':
            app->game_context.inputs.down  = true;
            break;       
        case KEY_LEFT:
        case 'a':
        case 'h':
            app->game_context.inputs.left  = true;
            break;
        case KEY_RIGHT:
        case 'd':
        case 'l':
            app->game_context.inputs.right = true;
            break;
    }
}
