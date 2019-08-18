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

This will generate the`liblwct.so` dynamic library file. This may sit on your `lib` folder of your project folder, or even on a special folder just for the LWCT libraries. It really depends on the scale of the project or on your degree of organization.

## Linking and compiling

Assuming that your projects' folder hierarchy looks something like this:

```
- include
	- lwct.h
- lib
	- liblwct.so
- src
	- foo.c
```

Then all you have to do is in the compiling. Simply add the dynamic library file, specifying the folder it's located at, and do the same thing for the include file.

``` bash
$ gcc -o foo foo.c -L../lib -llwct -I../include -include lwct.h -Wl,-R../lib
```

This is what each part of this command does:

* **-Lpath** adds a path that `gcc` will search for the library files
* **-llib** links the library file that may sit on the path specified before
* **-Ipath** adds a path that `gcc` will search for the header files
* **-include file** includes the header file at compilation time
* **-Wl** parses tokens to the linker, separated by commas
* **-Rpath** adds the library folder to the runtime library (needed for shared objects)

A sample Makefile can be located at the `demo` folder!

Make sure to place these last arguments at the end, since, according to the [gcc documentation](https://linux.die.net/man/1/gcc), files after those flags will not be linked to these libraries.
