# Makefile
# Compiling and linking test demos
# v.1.1.0

CC = gcc
LIBS = lwct
INCLUDES = lwct.h
LIBFOLDER = ../lib
INCLUDEFOLDER = ../include
COMPILEFLAGS = -w -I$(INCLUDEFOLDER)
LINKFLAGS = -w -L$(LIBFOLDER) $(addprefix -l, $(LIBS)) -Wl,-R$(LIBFOLDER)
SRC = $(wildcard *.c)
OUT = $(patsubst %.c, %.out, $(SRC))

all: $(OUT)

%.o: %.c
	$(CC) -c $< $(COMPILEFLAGS)

%.out: %.o
	$(CC) -o $@ $< $(LINKFLAGS)

clean:
	rm -f *.out

.PHONY: all clean
