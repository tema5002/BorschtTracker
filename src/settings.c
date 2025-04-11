#include "settings.h"

struct bt_settings_t global_settings = {};

void bt_initialize_settings() {
    global_settings.start_time = time(NULL);

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
