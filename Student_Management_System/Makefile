CC = gcc
CFLAGS = -std=c23 -march=native -flto -O3
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
