CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -Werror
INCLUDES = -Iinclude

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

TARGET_MAIN = main

all: directories $(TARGET_MAIN)

directories:
	@mkdir -p $(BUILD_DIR)

$(TARGET_MAIN): main.c $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET_MAIN) main.c $(OBJECTS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET_MAIN)
	@./$(TARGET_MAIN)

clean:
	rm -rf $(BUILD_DIR) $(TARGET_MAIN) $(TARGET_TEST)

.PHONY: all directories run clean
