CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wconversion -Wpedantic -std=c23 -fsanitize=address,undefined
LDFLAGS = -lm
SRC ?= ./characters.c
BIN = $(basename $(SRC))
OUT = build/program

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
