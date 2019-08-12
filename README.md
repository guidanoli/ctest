# CTest - unit test library

A lightweight testing library that operates only with:
* `assert` - checks whether the parameter is true
* `fatal_assert` - if the parameter is false, halts
* `show_log` - prints to screen if there was any false asserts

Currently, you must compile the source code by your own since dynamic libraries are just too complicated to be in a pretty straightforward to use library. On the other hand, if you do know how to write a good Makefile to compile the code in `.so` or `.dll`, please fork this repository.

## Linking and compiling

On your source file, simply include the CTest header file:

``` c
#include "../path/to/ctest.h"
```

And for compiling, simply compile with the object file:

``` bash
$ gcc -o ctest.o ctest.c -c
$ gcc -o myprog myprog.o ctest.o
```
