# Makefile
# For building the lwctl library and demos
# v.1.0.0

CC = gcc
CFLAGS = -w
LIBNAME = lwct
FILES = $(wildcard *.c)
OBJS = $(subst .c,.o,$(FILES))
LIBFILE = $(addsuffix .so, $(addprefix lib, $(LIBNAME)))
ALLSUBDIRS = $(dir $(wildcard */Makefile))
MAKEDIRS = src demo

all: $(MAKEDIRS)

$(MAKEDIRS):
	$(MAKE) -C $@ > /dev/null

clean:
	rm -f -r -d *.o *.so lib
	for dir in $(ALLSUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done > /dev/null

.PHONY: all $(MAKEDIRS) clean
