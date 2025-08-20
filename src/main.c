#include "app.h"

int main(void) {
    App app = {0};
    app_init(&app);

    app_run(&app);
    return 0;
}
