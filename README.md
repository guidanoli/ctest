# CTest - unit test library

A lightweight unit test library that operates only with:
* `assert` - checks whether the parameter is true
* `fatal_assert` - if the parameter is false, halts
* `show_log` - prints to screen if there was any false asserts

You can either bind the library or compile the source code all toghether.
It really depends whether you intend to test multiple modules or just one and
you really don't want to bother with dynamic binding.

## Shared Object (.so)

Simply run the following command on your terminal on the project root folder:

``` bash
$ make
```

## Linking and compiling

On your source file, simply include the CTest header file, eg:

``` c
#include "../lib/ctest/ctest.h"
```

And for compiling, simply add the library as so:

``` bash
$ gcc -o prog prog.o -L/../lib/ctest -ldllctest
```
