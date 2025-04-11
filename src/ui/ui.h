#pragma once
#include "../includes.h"

#define BT_RENDER_IF(t, f) if (!t) { t = true; f; do_refresh = true; }

void bt_render_ui(int x, int y, int w, int h);
