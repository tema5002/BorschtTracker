#pragma once
#include "includes.h"

typedef enum bt_log_level {
    BT_LOG_DEBUG = 0,
    BT_LOG_INFO = 1,
    BT_LOG_WARNING = 2,
    BT_LOG_ERROR = 3,
    BT_LOG_FATAL = 4
} bt_log_level;

#define BT_MIN_LOG_LEVEL BT_LOG_DEBUG
#define BT_MAX_LOG_LEVEL BT_LOG_FATAL

extern const char* bt_log_level_str[BT_MAX_LOG_LEVEL - BT_MIN_LOG_LEVEL + 1];
extern const char* bt_log_level_color[BT_MAX_LOG_LEVEL - BT_MIN_LOG_LEVEL + 1];

void bt_log(bt_log_level log_level, const char* format, ...);
