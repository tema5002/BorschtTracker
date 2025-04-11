#include "settings.h"

#include "terminal.h"
#include "logging.h"

struct bt_settings_t global_settings = {};

void bt_update_terminal_size() {
    endwin();
    clear();
    refresh();
    initscr();
    bt_log(BT_LOG_DEBUG, "New terminal size: %dx%d", COLS, LINES);
    BT_RESET_RENDER_STATE();
}

void handle_resizing(const int _) {
    (void)_; // unused argument warning
    bt_log(BT_LOG_DEBUG, "SIGWINCH received");
    bt_update_terminal_size();
}

void bt_initialize_settings() {
    global_settings.start_time = time(NULL);
    register_resize_handler(handle_resizing);

    bt_update_terminal_size();

    global_settings.volume = 255;
    global_settings.sample_rate = 48000;
    global_settings.buffer_size = 480;
    global_settings.audio_channels = 2;

    global_settings.log_level = BT_LOG_DEBUG;
    BT_RESET_RENDER_STATE();

    global_settings.current_mod.fp = NULL;
    create_empty_bt_module(&global_settings.current_mod.mod);

    memset(global_settings.recent_files, 0, sizeof(global_settings.recent_files));
}
