# Compiler locations:
# Latest GCC: /usr/local/gcc-10.2.0/bin/gcc-10.2
# Latest Clang: /usr/local/clang_10.0.1/bin/clang-10
# Debian 10 default GCC: /usr/bin/gcc
# Debian 10 default Clang: /usr/bin/clang
# Debain 10 default CC (after many symlinks): /usr/bin/gcc

SHELL := /usr/bin/bash
.SHELLFLAGS := -o errexit -o nounset -o pipefail -c

CC := /usr/local/gcc-10.2.0/bin/gcc-10.2
VAL_CC := /usr/local/clang_10.0.1/bin/clang-10
MKDIR_P ?= mkdir -p

TARGET_EXEC := a.out
VAL_TARGET_EXEC := val.out
BUILD_DIR := ./build
VAL_BUILD_DIR := ./build/val_build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) ! -name *89.c -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
VAL_OBJS := $(SRCS:%=$(VAL_BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
VAL_DEPS := $(VAL_OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS ?= -save-temps=obj -O0 -g -fsanitize=address -march=native -pedantic\
					-std=c18 -Wall -Wextra -Wduplicated-cond -Wduplicated-branches\
					-Wshadow -Wstrict-prototypes
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
LDFLAGS ?= -fsanitize=address
VAL_CFLAGS ?= -O0 -g -march=native -pedantic -save-temps=obj -std=c89 -Wall\
							-Wextra -Wshadow -Wstrict-prototypes
VAL_LDFLAGS ?=

.PHONY: all cdoodles clean valgrind

all: cdoodles valgrind

cdoodles: $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEPS)

valgrind: $(BUILD_DIR)/$(VAL_TARGET_EXEC)

$(BUILD_DIR)/$(VAL_TARGET_EXEC): $(VAL_OBJS)
	$(VAL_CC) $(VAL_OBJS) -o $@ $(VAL_LDFLAGS)

$(VAL_BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(VAL_CC) $(CPPFLAGS) $(VAL_CFLAGS) -c $< -o $@

-include $(VAL_DEPS)

clean:
	$(RM) -r $(BUILD_DIR)
