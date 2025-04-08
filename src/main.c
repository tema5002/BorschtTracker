#include "includes.h"

#include "ui/ui.h"
#include "settings.h"
#include "logging.h"
#include "utils.h"


int main(int argc, char* argv[]) {
    bt_log(BT_LOG_DEBUG, "Starting BorschtTracker");
    for (int i = 0; i < argc; i++) {
    	bt_log(BT_LOG_DEBUG, "argv[%i] = %s\n", i, argv[i]);
    }

    bt_initialize_settings();
    HIDE_CURSOR();

    time_t last_second = 0;

    while (1) {
        struct timeval timeout = {
            .tv_sec = 0,
            .tv_usec = 1000000 - time(NULL) % 1 * 1000000
        };

        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

        time_t now = time(NULL);
        
        if (now > last_second) {
            last_second = now;
            global_settings.render_state.title_header = false;
        }

        bt_render_ui(0, 0, global_settings.window.x, global_settings.window.y);
    
    }
    return 0;
}
