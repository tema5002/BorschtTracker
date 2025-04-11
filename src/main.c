#include "includes.h"

#include "ui/ui.h"
#include "settings.h"
#include "logging.h"
#include "input_handler.h"
#include "init.h"

int main(int argc, char* argv[]) {
    bt_main_initialize();

    bt_log(BT_LOG_DEBUG, "Starting BorschtTracker");
    for (int i = 0; i < argc; i++) {
    	bt_log(BT_LOG_DEBUG, "argv[%i] = %s\n", i, argv[i]);
    }

    time_t last_second = 0;

    bt_render_ui(0, 0, COLS, LINES);

    while (true) {
        packed_string_t input;
        handle_input(&input);
        if (input == BT_PACK_STRING_CHAR('q')) bt_stop_execution();

        const time_t now = time(NULL);
        if (now > last_second) {
            last_second = now;
            global_settings.render_state.title_header = false;
        }

        bt_render_ui(0, 0, COLS, LINES);
    }
    return 0;
}
