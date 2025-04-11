#include "input_handler.h"
#include "logging.h"

void handle_input(packed_string_t* input) {
    timeout(1000 - (time(NULL) % 1000));

    const int ch = getch();

    if (ch == ERR) {
        bt_log(BT_LOG_DEBUG, "getch() timed out");
        *input = 0;
        return;
    }

    *input = BT_PACK_STRING_CHAR(ch);

    if (' ' <= (unsigned char)*input && (unsigned char)*input <= 0x7F) {
        bt_log(BT_LOG_DEBUG, "input: '%c'", *input);
    }
    else {
        bt_log(BT_LOG_DEBUG, "input: '\\0x%02X'", (unsigned char)*input);
    }
}
