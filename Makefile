CC = gcc
CFLAGS = -w
FILES = $(wildcard *.c)
OBJS = $(subst .c,.o,$(FILES))

libctest.so: $(OBJS)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC $< $(CFLAGS)

clean:
	rm -f *.o *.so
