CC = gcc
INCLUDEDIR = ../include
LIBDIR = ../lib
CFLAGS = -w -I$(INCLUDEDIR) -L$(LIBDIR)
LIBNAME = lwct
FILES = $(wildcard *.c)
OBJS = $(subst .c,.o,$(FILES))
LIBFILE = $(addsuffix .so, $(addprefix lib, $(LIBNAME)))
LIBDIR = ../lib/
LIBPATH = $(addprefix $(LIBDIR),$(LIBFILE))

all: $(LIBPATH)

$(LIBPATH): $(OBJS)
	mkdir -p $(LIBDIR)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC $< $(CFLAGS)

clean:
	rm -f *.o *.so

.PHONY: all $(MAKEDIRS) clean
