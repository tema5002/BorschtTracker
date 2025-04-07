#include "logging.h"

#include "settings.h"

const char* bt_log_level_str[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL"
};

const char* bt_log_level_color[] = {
    "\033[0;37m",
    "\033[0;36m",
    "\033[0;33m",
    "\033[0;31m",
    "\033[1;31m"
};

void bt_log(bt_log_level log_level, const char* format, ...) {
    if (global_settings.log_level > log_level)
        return;

    va_list args;
    va_start(args, format);

    fprintf(stderr, "%s", bt_log_level_color[log_level]);
    fprintf(stderr, "[%s] ", bt_log_level_str[log_level]);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\033[0m");
    fprintf(stderr, "\n");

    if (log_level == BT_LOG_FATAL) exit(EXIT_FAILURE);

    va_end(args);
}
