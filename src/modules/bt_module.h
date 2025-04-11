#pragma once
#include "../includes.h"

#include "bt_pattern.h"

struct bt_module {
    char name[65];
    int bpm;
    int tempo;
    struct {
        struct bt_pattern* data;
        uint16_t length;
    } patterns;
};

void create_empty_bt_module(struct bt_module* mod);
