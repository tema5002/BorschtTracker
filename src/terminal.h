#pragma once
#include "includes.h"

#include <signal.h>

void bt_get_terminal_size(int* width, int* height);
void register_resize_handler(__sighandler_t callback);
