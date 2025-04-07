#pragma once
#include "../includes.h"

#define BT_RENDER_IF(t, f) if (!t) { t = true; f; }

void bt_render_all(int x, int y, int w, int h);
