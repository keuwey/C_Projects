CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wconversion -Wpedantic -std=c23 -march=native -flto -fsanitize=address,undefined -O2
LDFLAGS = -lm
SRC ?= ./src/main.c
BIN = $(basename $(SRC))
OUT = build/program

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
