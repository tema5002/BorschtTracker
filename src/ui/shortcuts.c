#include "shortcuts.h"

#include "../init.h"

struct bt_shortcut_t bt_shortcuts[] = {
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
    {"^P", "placeholder     "},
};

void bt_render_shortcuts(
        const int x,
        const int y,
        const int w,
        const int h
) {
    int current_y = y;
    int current_x = x;

    move(current_y, current_x);

    const int shortcuts_count = w / BT_SHORTCUT_WIDTH;
    const int extra_space = w - shortcuts_count * BT_SHORTCUT_WIDTH;
    const int space_between = shortcuts_count > 1 ? extra_space / (shortcuts_count - 1) : extra_space;

    for (int s = 0; s < BT_SHORTCUTS_AMOUNT; s++) {
        if (current_x + BT_SHORTCUT_WIDTH > w) {
            current_x = x;
            current_y++;
            if (current_y > h + y) return;
            move(current_y, current_x);
        }

        attron(COLOR_PAIR(BT_COLOR_PAIR_SHORTCUTS));
        printw("%s", bt_shortcuts[s].key);
        attroff(COLOR_PAIR(BT_COLOR_PAIR_SHORTCUTS));
        printw(" %s", bt_shortcuts[s].description);
        PRINT_SPACES(space_between);

        current_x += BT_SHORTCUT_WIDTH + space_between; // Add distributed spacing
    }
}
