#include "terminal.h"

#include "logging.h"
#include "settings.h"

void register_resize_handler(const __sighandler_t callback) {
    struct sigaction sa;

    sa.sa_handler = callback;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGWINCH, &sa, NULL) == -1) {
        bt_log(BT_LOG_ERROR, "Failed to register SIGWINCH handler.");
    }
}

void bt_update_terminal_size() {
    endwin();
    clear();
    refresh();
    initscr();
    bt_log(BT_LOG_DEBUG, "New terminal size: %dx%d", COLS, LINES);
    BT_RESET_RENDER_STATE();
}