# Compiler locations:
#
# Latest GCC: /usr/local/gcc-10.2.0/bin/gcc-10.2
# Debian 10 default GCC: /usr/bin/gcc
# Debian 10 default Clang: /usr/bin/clang

SHELL :=/usr/bin/env bash
.SHELLFLAGS :=-o errexit -o nounset -o pipefail -c

CC :=/usr/local/gcc-10.2.0/bin/gcc-10.2

TARGET_EXEC := a.out
BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS ?= -O0 -g -fsanitize=address -march=native -pedantic -pipe -std=c17\
					-Wall -Wextra
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
LDFLAGS ?= -fsanitize=address -lncurses

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
