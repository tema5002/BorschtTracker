#include "terminal.h"

#include "logging.h"

void bt_get_terminal_size(int* width, int* height) {
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        bt_log(BT_LOG_ERROR, "Error getting terminal size. Using fallback values.");
        *width = 80;
        *height = 24;
    }
    else {
        *width = ws.ws_col;
        *height = ws.ws_row;
    }
    bt_log(BT_LOG_DEBUG, "New terminal size: %dx%d", *width, *height);
}

void register_resize_handler(const __sighandler_t callback) {
    struct sigaction sa;

    sa.sa_handler = callback;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGWINCH, &sa, NULL) == -1) {
        bt_log(BT_LOG_ERROR, "Failed to register SIGWINCH handler.");
    }
}
