# LWCTL - lightweight C test library

A lightweight testing library that operates only with:
* `assert` - checks whether the parameter is true
* `fatal_assert` - if the parameter is false, halts
* `show_log` - prints to screen if there was any false asserts

## Building the library

It's just as simple as using the library itself.

Just type the following command on your terminal at the source folder:

``` bash
$ make
```

This will generate the`liblwctest.so` dynamic library file. This may sit on your `lib` folder of your project or even on your `usr/lib/` standard libraries directory folder.

## Linking and compiling

Assuming that your projects' folder hierarchy looks something like this:

```
- include
	- lwct.h
- lib
	- liblwctl.so
- src
	- foo.c
```

On your source file, simply include the LWCT header file:

``` c
foo.c

#include "../include/lwct.h"
...
```

And for compiling, simply compile with the dynamic library file, specifying the folder it's located at:

``` bash
$ gcc -o foo foo.c -L../lib -llwctl -Wl,-R../lib
```

Make sure to place these last arguments at the end, since, according to the [gcc documentation](https://linux.die.net/man/1/gcc), files after those flags will not be linked to these libraries.
