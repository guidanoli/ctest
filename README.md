
# LWCTL - lightweight C test library

A lightweight testing library that operates only with the following basic functionalities:
* `assertion` - checks the boolean value of a statement
* `fatal assertion` - identical to normal assertion, but halts if the statement is false
* `assertion log` - prints to screen the assertion log (#errors/#assertions)

## Building the library

It's just as simple as using the library itself.

Just type the following command on your terminal at the source folder:

``` bash
$ make
```

This will generate the`liblwct.so` dynamic library file on the `lib` folder.

## Linking and compiling

Assuming that your project folder hierarchy looks something like this:

```
- include/lwct.h
- lib/liblwct.so
- src/my_test.c
```

Then all you have to do is in the compiling. Simply add the dynamic library file, specifying the folder it's located at. The same thing goes for the header file.

``` bash
$ pwd
my_project/src
$ gcc -o test my_test.c -L../lib -llwct -I../include -include lwct.h -Wl,-R../lib
```

This is what each part of this command does:

* **-Lpath** adds a path that `gcc` will search for the library files
* **-llib** links the library file that may sit on the path specified before
* **-Ipath** adds a path that `gcc` will search for the header files
* **-include file** includes the header file at compilation time
* **-Wl** parses tokens to the linker, separated by commas
* **-Rpath** adds the library folder to the runtime library (needed for shared objects)

If you don't want to write the same long command over and over again for all your tests, there is a sample Makefile located at the `demo` folder!
