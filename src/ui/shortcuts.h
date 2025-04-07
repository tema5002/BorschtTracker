#pragma once
#include "../includes.h"

#include "../utils.h"

struct bt_shortcut {
    char key[3];
    char description[12];
};

extern struct bt_shortcut bt_shortcuts[];

#define BT_SHORTCUTS_PADDING 4
#define BT_SHORTCUTS_AMOUNT (int)(sizeof(bt_shortcuts) / sizeof(bt_shortcuts[0]))
#define BT_SHORTCUT_WIDTH (int)(CONST_STRLEN(bt_shortcuts[0].key) + CONST_STRLEN(bt_shortcuts[0].description) + BT_SHORTCUTS_PADDING + 1)

void bt_render_shortcuts(int x, int y, int w);
