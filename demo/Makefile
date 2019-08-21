CC = gcc
LIBS = lwct
INCLUDES = lwct.h
LIBFOLDER = ../lib
INCLUDEFOLDER = ../include
CFLAGS = -w -L$(LIBFOLDER) -I$(INCLUDEFOLDER) $(addprefix -l, $(LIBS)) \
	$(addprefix -include, $(INCLUDES)) -Wl,-R$(LIBFOLDER)
SRC = $(wildcard *.c)
OUT = $(patsubst %.c, %.out, $(SRC))

all: $(OUT)

%.out: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f *.out

.PHONY: all clean
