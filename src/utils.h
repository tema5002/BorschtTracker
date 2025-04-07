#pragma once

#include "includes.h"

// you talk about antimatter so much i thought you were tema5002

#include "logging.h"

#define MOVE_CURSOR(x, y) printf("\e[%d;%dH", (y) + 1, (x) + 1)
#define HIDE_CURSOR() fputs("\e[?25l", stdout)
#define CLEAR_SCREEN() fputs("\033[2J", stdout);

#define PROGRAM_NAME "BorschtTracker"
#define PROGRAM_NAME_FULL PROGRAM_NAME " v0.0.0.0.0.1"
#define CONST_STRLEN(s) (sizeof(s) - 1)
#define PRINT_SPACES(n) printf("%*s", (n), "")

inline void* safe_malloc(const size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        bt_log(BT_LOG_FATAL, "Memory allocation failed for %zu bytes!", size);
    }
    return ptr;
}

typedef struct bt_vector2 {
    int x, y;
} bt_vector2;
