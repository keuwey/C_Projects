CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O2
SRC = $(wildcard src/*.c)
OUT = build/main

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@

run: all
	./$(OUT)

clean:
	rm -rf build
