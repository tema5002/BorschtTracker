#include "all.h"

#include "pattern_editor.h"
#include "title_header.h"
#include "shortcuts.h"

#include "../settings.h"

void bt_render_all(
        int x,
        int y,
        int w,
        int h
) {
    BT_RENDER_IF(global_settings.render_state.title_header, bt_render_title_header(x, y, w));
    BT_RENDER_IF(global_settings.render_state.shortcuts, bt_render_shortcuts(x, h - 2, w));
    BT_RENDER_IF(global_settings.render_state.pattern_editor, bt_render_pattern_editor(x, y + 1, w, h - 2));
}
