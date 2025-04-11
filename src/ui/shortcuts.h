#pragma once
#include "../includes.h"

#include "../utils.h"

struct bt_shortcut_t {
    char key[3];
    char description[17];
};

extern struct bt_shortcut_t bt_shortcuts[];

#define BT_SHORTCUTS_AMOUNT (int)(sizeof(bt_shortcuts) / sizeof(bt_shortcuts[0]))
#define BT_SHORTCUT_WIDTH (int)(CONST_STRLEN(bt_shortcuts[0].key) + 1 + CONST_STRLEN(bt_shortcuts[0].description))

void bt_render_shortcuts(int x, int y, int w, int h);
