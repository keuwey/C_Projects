# ============================================================
# Project configuration
# ============================================================

PROJECT_NAME := app
CC           := gcc

SRC_DIR      := src
INC_DIR      := include
BIN_DIR      := bin
BUILD_DIR    := build

DEV_DIR      := $(BUILD_DIR)/dev
REL_DIR      := $(BUILD_DIR)/release

# ============================================================
# Source files
# ============================================================

SRCS := $(wildcard $(SRC_DIR)/*.c)

DEV_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(DEV_DIR)/%.o)
REL_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(REL_DIR)/%.o)

# ============================================================
# Flags
# ============================================================

CPPFLAGS := -I$(INC_DIR)

DEV_CFLAGS := \
	-std=c23 \
	-Wall -Wextra -Werror -Wshadow -Wconversion -Wpedantic \
	-Wnull-dereference -Wdouble-promotion \
	-g \
	-fsanitize=address,undefined \
	-fno-omit-frame-pointer

REL_CFLAGS := \
	-std=c23 \
	-O3 \
	-march=native \
	-flto \
	-fno-plt

DEV_LDFLAGS := -fsanitize=address,undefined -lm
REL_LDFLAGS := -flto -lm

# ============================================================
# Default target
# ============================================================

.PHONY: all
all: dev

# ============================================================
# Development build
# ============================================================

.PHONY: dev
dev: $(BIN_DIR)/$(PROJECT_NAME)_dev

$(BIN_DIR)/$(PROJECT_NAME)_dev: $(DEV_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(DEV_OBJS) $(DEV_LDFLAGS) -o $@

$(DEV_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(DEV_DIR)
	$(CC) $(CPPFLAGS) $(DEV_CFLAGS) -c $< -o $@

# ============================================================
# Release build
# ============================================================

.PHONY: release
release: $(BIN_DIR)/$(PROJECT_NAME)

$(BIN_DIR)/$(PROJECT_NAME): $(REL_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(REL_OBJS) $(REL_LDFLAGS) -o $@

$(REL_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(REL_DIR)
	$(CC) $(CPPFLAGS) $(REL_CFLAGS) -c $< -o $@

# ============================================================
# Utilities
# ============================================================

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: rebuild
rebuild: clean all

.PHONY: run
run: dev
	./$(BIN_DIR)/$(PROJECT_NAME)_dev

.PHONY: run-release
run-release: release
	./$(BIN_DIR)/$(PROJECT_NAME)

# ============================================================
# Diagnostics
# ============================================================

.PHONY: info
info:
	@echo "Sources:   $(SRCS)"
	@echo "Dev objs:  $(DEV_OBJS)"
	@echo "Rel objs:  $(REL_OBJS)"
