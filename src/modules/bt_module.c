#include "bt_module.h"

#include <string.h>

void create_empty_bt_module(struct bt_module* mod) {
    memset(mod->name, 0, sizeof(mod->name));
    mod->bpm = 125;
    mod->tempo = 6;
    mod->patterns.length = 1;
    mod->patterns.data = NULL;
}