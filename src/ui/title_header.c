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
    MOVE_CURSOR(x, y);
    printf("\e[30m\e[46m");

    const char* filename = global_settings.current_mod.fp;
    if (filename == NULL)
        filename = "New file";

    char system_time[20];
    get_system_time(system_time);

    const int name_length = CONST_STRLEN(PROGRAM_NAME_FULL);
    const int file_length = strlen(filename);
    const int time_length = CONST_STRLEN(system_time);

    const int left_right_padding = w / 80;
    const int file_start = (w - file_length) / 2 - name_length - left_right_padding;
    const int time_start = w - left_right_padding - name_length - file_start - file_length - time_length - left_right_padding;

    PRINT_SPACES(left_right_padding);
    fputs(PROGRAM_NAME_FULL, stdout);
    PRINT_SPACES(file_start);
    fputs(filename, stdout);
    PRINT_SPACES(time_start);
    fputs(system_time, stdout);
    PRINT_SPACES(left_right_padding);

    printf("\e[m");
    fflush(stdout);
}
