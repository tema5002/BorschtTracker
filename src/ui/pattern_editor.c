#include "pattern_editor.h"

#include "../utils.h"

void bt_render_pattern_editor(
        const int x,
        const int y,
        const int w,
        const int h
) {
    for (int j = y; j < h; j++) {
        move(j, x);
        for (int i = x; i < w; i++) {
            if (i == x ||
                j == y ||
                i == w - 1 ||
                j == h - 1
            ) {
                printw("O");
            }
            else {
                printw("-");
            }
        }
    }
    mvprintw(y + 2, x + 2, "pattern editror");
}
