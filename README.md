# errno

A small command line utility program to quickly look up C standard library error codes, for those of us too lazy to check `man errno`. Inspired by [`errno` for SerenityOS](https://github.com/SerenityOS/serenity/blob/master/Userland/Utilities/errno.cpp) and [`errno` from moreutils](https://joeyh.name/code/moreutils/) (which you should probably use instead of this).


## Usage

```
$ errno         # print a list of all errors
$ errno 32      # look up an error by number
$ errno EACCES  # look up an error by name
```


## Building from source

Building requires a C compiler (gcc or clang recommended), only Linux is supported.
```
$ git clone https://github.com/Andriamanitra/errno
$ cd errno
$ make build
$ ./errno  # check that it works
```
