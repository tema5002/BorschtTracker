#include "shortcuts.h"

struct bt_shortcut bt_shortcuts[] = {
    {"^C", "copy idk   "},
    {"^P", "placeholder"},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^C", "copy idk   "},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
    {"^P", "placeholder"},
};

void bt_render_shortcuts(
        int x,
        int y,
        int w
        // height is always 2
) {
    int current_width = 0;
    bool second = false;

    MOVE_CURSOR(x, y);
    for (int s = 0; s < BT_SHORTCUTS_AMOUNT; s++) {
        if (current_width + BT_SHORTCUT_WIDTH > w) {
            current_width = 0;
            y++;
            if (second) return;
            else second = true;
            MOVE_CURSOR(x, y);
        }
        printf("\e[0;7m%s\e[m %s", bt_shortcuts[s].key, bt_shortcuts[s].description);
        fflush(stdout);
        PRINT_SPACES(BT_SHORTCUTS_PADDING);
        current_width += BT_SHORTCUT_WIDTH;
    }
}
