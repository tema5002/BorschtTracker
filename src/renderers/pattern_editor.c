#include "pattern_editor.h"

#include "../utils.h"

void bt_render_pattern_editor(
        int x,
        int y,
        int w,
        int h
) {
    for (int j = y; j < h; j++) {
        MOVE_CURSOR(x, j);
        for (int i = x; i < w; i++) {
            if (i == x ||
                j == y ||
                i == w - 1 ||
                j == h - 1
            ) {
                printf("O");
            }
            else {
                printf("-");
            }
        }
        fflush(stdout);
    }
    MOVE_CURSOR(x + 2, y + 2);
    fputs("pattern editror", stdout);
    fflush(stdout);
}
