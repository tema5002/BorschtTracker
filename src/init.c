#include "init.h"

#include "settings.h"

void bt_stop_execution() {
    endwin();
}

void bt_main_initialize() {
    initscr();

    start_color();
    use_default_colors();
    init_pair(BT_COLOR_PAIR_TITLE_HEADER, COLOR_BLACK, COLOR_CYAN);
    init_pair(BT_COLOR_PAIR_SHORTCUTS, COLOR_BLACK, COLOR_WHITE);

    cbreak();
    noecho();
    curs_set(0);
    //keypad(stdscr, TRUE);
    atexit(bt_stop_execution);

    //setlocale(LC_ALL, "");
    bt_initialize_settings();
}