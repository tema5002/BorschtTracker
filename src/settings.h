#pragma once
#include "includes.h"

#include "logging.h"
#include "modules/bt_module.h"

struct bt_settings_t {
    time_t start_time;

    int volume;
    int sample_rate;
    int buffer_size;
    int audio_channels;

    bt_log_level log_level;
    struct {
    	bool title_header;
    	bool shortcuts;
    	bool pattern_editor;
    } render_state;

    struct {
        char* fp;
        struct bt_module mod;
    } current_mod;
    char* recent_files[10];
};

#define BT_RESET_RENDER_STATE() memset(&global_settings.render_state, 0, sizeof(global_settings.render_state))

extern struct bt_settings_t global_settings;

void bt_initialize_settings();
