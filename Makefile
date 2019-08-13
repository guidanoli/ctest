CC = gcc
CFLAGS = -w
LIBNAME = lwctest
FILES = $(wildcard *.c)
OBJS = $(subst .c,.o,$(FILES))
LIBFILE = $(addsuffix .so, $(addprefix lib, $(LIBNAME)))

$(LIBFILE): $(OBJS)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC $< $(CFLAGS)

clean:
	rm -f *.o *.so
