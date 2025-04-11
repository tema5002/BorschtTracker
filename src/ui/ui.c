#include "ui.h"

#include "pattern_editor.h"
#include "title_header.h"
#include "shortcuts.h"

#include "../settings.h"

void bt_render_ui(
        const int x,
        const int y,
        const int w,
        const int h
) {
    bool do_refresh = false;
    BT_RENDER_IF(global_settings.render_state.title_header, bt_render_title_header(x, y, w));
    BT_RENDER_IF(global_settings.render_state.shortcuts, bt_render_shortcuts(x, h - 2, w, 2));
    BT_RENDER_IF(global_settings.render_state.pattern_editor, bt_render_pattern_editor(x, y + 1, w, h - 2));
    if (do_refresh) refresh();
}
