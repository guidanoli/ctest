CC = gcc
CFLAGS = -w
LIBNAME = lwct
FILES = $(wildcard *.c)
OBJS = $(subst .c,.o,$(FILES))
LIBFILE = $(addsuffix .so, $(addprefix lib, $(LIBNAME)))
SUBDIRS = $(dir $(wildcard */Makefile))

all: $(LIBFILE) $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ > /dev/null

$(LIBFILE): $(OBJS)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC $< $(CFLAGS)

clean:
	rm -f *.o *.so
	for dir in $(SUBDIRS); do \
      $(MAKE) -C $$dir clean; \
  done > /dev/null

.PHONY: all $(SUBDIRS) clean
