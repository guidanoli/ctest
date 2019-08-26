
# lwctl - lightweight C test library

The library basically operates with test cases that run boolean assertions and then print colourful logs onto screen. That's what makes lwctl so accessible, yet powerful.

![LWCTL colourful assertions](https://i.imgur.com/aLMQK8C.png)

## Building the library

It's just as simple as using the library itself.

Just run the `make` command on your terminal in the same folder of the README file. This will generate the`liblwct.so` dynamic library file on the `lib` folder.

## Building tests

Assuming that your project folder hierarchy looks something like this:

```
- include/lwct.h # LWCT API
- include/foo.h # module header
- lib/liblwct.so # LWCT library
- src/t.foo.c # module test
- src/foo.c # module source
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

## API

The interface is provided by the `lwct.h` header file. This should be included in your test files. Following are the basic commands and how they work.

### Assertions

The `lwct_assert(S, bool)` and `lwct_fatal_assert(S, bool)` macros take two arguments:
* The test state (often called S)
* The boolean sentence to be asserted
	* FALSE (0) = error message
	* TRUE (any other value) = success message

The difference between the two macro is that when a false statement is asserted with `lwct_fatal_assert`, the program halts. This may be desirable when, for example, a data structure could not be allocated and dereferencing a `NULL` pointer would signal `SEGSENV`, or `Segmentation fault (core dumped)`. This also ensure that log will be printed before halting.

### Tests

Tests are the core of any testing facility. In the LWCT, these are simply functions implemented by the user and passed to the lwct library to create a proper testing environment. This environment keeps track of the number of assertions, errors, and current file, which is printed out at the end in a small log.

#### Submitting your test

The LWCTL run the tests for you! Simply implement your test case with the `void func(lwct_state *S)` signature, and then call `lwct_submit_test(func)`. It's that easy. At the end, the log is printed out.

#### Submitting your batch job

If you want to run tests that runs N times, we got you covered too! Simply implement your test case with the `void func(lwct_state *S, unsigned long i)` signature, and then call the `lwct_submit_test(func, N)` for N jobs. The second argument you receive is the iteration, spanning from 0 to N-1. After N repetitions, the log is printed out.
