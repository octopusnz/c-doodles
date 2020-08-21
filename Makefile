CC :=/usr/bin/gcc
CFLAGS :=-O0 -g -march=native -pedantic -pipe -std=c18 -Wall -Wextra
LFLAGS :=-lncurses
OBJDIR :=build/
OBJS :=$(OBJDIR)main
SHELL :=/usr/bin/env bash
.SHELLFLAGS :=-o errexit -o nounset -o pipefail -c

# Can't make the objects without dir
#$(OBJS): | $(OBJDIR)

# Identify targets that are not real
.PHONY: clean setup

# Clear out the suffixes and re-set
.SUFFIXES:
.SUFFIXES: .c .o

setup:
	mkdir build/

main: main.c
	$(CC) $(CFLAGS) -o $(OBJDIR)$@ $< $(LFLAGS)

clean :
	rm $(OBJS)
