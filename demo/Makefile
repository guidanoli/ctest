CC = gcc
CFLAGS = -w -L.. -llwctl -Wl,-R..
SRC = $(wildcard *.c)
OUT = $(patsubst %.c, %.out, $(SRC))

all: $(OUT)

%.out: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f *.out

.PHONY: all clean
