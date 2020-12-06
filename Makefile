CFLAGS=-pedantic -std=c18 -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wshadow -Wstrict-prototypes
SRC_DIRS:= ./src
SOURCES:=  $(wildcard ./src/*.c) $(wildcard ./src/headers/*.h)

c_doodles: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)
