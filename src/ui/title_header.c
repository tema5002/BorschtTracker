#include "title_header.h"

#include "../utils.h"
#include "../settings.h"

void get_system_time(char *buffer) {
    strftime(buffer, 20, "%Y-%m-%d %H:%M.%S", localtime(&(time_t){time(NULL)}));
}

void bt_render_title_header(
        const int x,
        const int y,
        const int w
) {
    const char* filename = global_settings.current_mod.fp;
    if (filename == NULL)
        filename = "New file";

    char system_time[20];
    get_system_time(system_time);

    move(y, x);
    attron(COLOR_PAIR(1));

    const int name_length = CONST_STRLEN(PROGRAM_NAME_FULL);
    const int file_length = (int)strlen(filename);
    const int time_length = CONST_STRLEN(system_time);
    const int total_length = name_length + file_length + time_length;

    if (total_length + 2 > w) {
        if (name_length + file_length + 1 > w) {
            // only print the program name
            const int padding = (w - name_length) / 2;
            PRINT_SPACES(padding);
            printw("%s", PROGRAM_NAME_FULL);
            PRINT_SPACES(padding);
        }
        else {
            // print program name and filename
            printw("%s", PROGRAM_NAME_FULL);
            PRINT_SPACES(w - name_length - file_length);
            printw("%s", filename);
        }
    }
    else {
        int left_right_padding = (w - total_length) / 16;
        if (left_right_padding > 2) left_right_padding = 2;

        const int padding = (w - left_right_padding * 2 - total_length) / 2;

        PRINT_SPACES(left_right_padding);
        printw("%s", PROGRAM_NAME_FULL);
        PRINT_SPACES(padding);
        printw("%s", filename);
        PRINT_SPACES(padding);
        printw("%s", system_time);
        PRINT_SPACES(left_right_padding);
    }

    attroff(COLOR_PAIR(1));
}