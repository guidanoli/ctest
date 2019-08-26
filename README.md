
# lwctl - lightweight C test library

The lightweight testing library operates with test cases with boolean assertions only. That's  what makes lwctl to easy to use and portable.

## Building the library

It's just as simple as using the library itself.

Just type `make` on your terminal in the same folder of the README file. This will generate the`liblwct.so` dynamic library file on the `lib` folder.

## Building tests

Assuming that your project folder hierarchy looks something like this:

```
- include/lwct.h		# LWCT API
- include/foo.h		# module header
- lib/liblwct.so		# LWCT library
- src/t.foo.c		# module test
- src/foo.c			# module source
```

And that your test looks something like this:

``` c
/*
 * t.foo.c
 */

#include "lwct.h"
#include "foo.h"

void test_foo(lwct_state *S)
{
	foo *f = foo_create();
	lwct_assert(S, foo_empty(f));
	foo_add(f, 1);
	lwct_assert(S, !foo_empty(f));
	foo_remove(f, 1);
	lwct_assert(S, foo_empty(f));
	...
	foo_destroy(f);
}

int main(void)
{
	lwct_submit_test(test_foo);
	return 0;
}
```

### Compiling

``` bash
$ gcc -c t.foo.c -I../include
```

* **-Ipath** adds a path that `gcc` will search for the header files

### Linking

``` bash
$ gcc t.foo.o foo.o -L../lib -llwct -Wl,-R../lib
```

* **-Lpath** adds a path that `gcc` will search for library files
* **-lx** links program to the libx.so dynamic library file
* **-Wl,-Rpath** adds the library folder to the runtime library (needed for shared objects)

If you don't want to write the same long command over and over again for all your tests, there is a sample Makefile located at the `demo` folder for you!
