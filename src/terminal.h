#pragma once
#include "includes.h"

#include <signal.h>

void register_resize_handler(__sighandler_t callback);
void bt_update_terminal_size();