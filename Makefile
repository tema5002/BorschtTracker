SRC_DIR = src
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -O3 -std=c99 -D_XOPEN_SOURCE=700
TARGET = program

LDFLAGS = -O3 -lncurses

SRCS = $(shell find src -type f -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $< -o $@ $(CFLAGS) -c

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
