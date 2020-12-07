GCC_CFLAGS=-pedantic -std=c17 -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wshadow -Wstrict-prototypes
CLANG_CFLAGS=-pedantic -std=c17 -Wall -Wextra
SOURCES:=  $(wildcard ./src/*.c)

c_doodles_gcc: $(SOURCES)
	$(CC) $(GCC_CFLAGS) $(SOURCES)

c_doodles_clang: $(SOURCES)
	$(CC) $(CLANG_CFLAGS) $(SOURCES)
