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

    MOVE_CURSOR(x, y);
    printf("\e[30m\e[46m");

    const int name_length = CONST_STRLEN(PROGRAM_NAME_FULL);
    const int file_length = strlen(filename);
    const int time_length = CONST_STRLEN(system_time);
    const int total_length = name_length + file_length + time_length;

    if (total_length + 2 > w) {
        if (name_length + file_length + 1 > w) {
            // only print the program name
            const int padding = (w - name_length) / 2;
            PRINT_SPACES(padding);
            fputs(PROGRAM_NAME_FULL, stdout);
            PRINT_SPACES(padding);
        }
        else {
            // print program name and filename
            fputs(PROGRAM_NAME_FULL, stdout);
            PRINT_SPACES(w - name_length - file_length);
            fputs(filename, stdout);
        }
    }
    else {
        int left_right_padding = (w - total_length) / 16;
        if (left_right_padding > 2) left_right_padding = 2;

        const int padding = (w - left_right_padding * 2 - total_length) / 2;

        PRINT_SPACES(left_right_padding);
        fputs(PROGRAM_NAME_FULL, stdout);
        PRINT_SPACES(padding);
        fputs(filename, stdout);
        PRINT_SPACES(padding);
        fputs(system_time, stdout);
        PRINT_SPACES(left_right_padding);
    }

    printf("\e[m");
    fflush(stdout);
}
