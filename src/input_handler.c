#include "input_handler.h"
#include "logging.h"
#include "terminal.h"

void handle_input(packed_string_t* input) {
    timeout(1000 - (time(NULL) % 1000));

    const int ch = getch();

    if (ch == ERR) {
        bt_log(BT_LOG_DEBUG, "getch() timed out");
        *input = 0;
    }
    else if (ch == KEY_RESIZE) {
        bt_update_terminal_size();
        *input = 0;
    }
    else if (' ' <= *input && *input <= 0x7F) {
        bt_log(BT_LOG_DEBUG, "input: '%c'", *input);
        *input = BT_PACK_STRING_CHAR(ch);
    }
    else {
        bt_log(BT_LOG_DEBUG, "input: '\\0x%02X'", (unsigned char)*input);
        *input = ch;
    }
}
