#include "terminal.h"

#include "logging.h"
#include "utils.h"

void register_resize_handler(const __sighandler_t callback) {
    struct sigaction sa;

    sa.sa_handler = callback;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGWINCH, &sa, NULL) == -1) {
        bt_log(BT_LOG_ERROR, "Failed to register SIGWINCH handler.");
    }
}
