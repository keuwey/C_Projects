CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wconversion -Wpedantic -std=c23 -march=native -flto -O2
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
