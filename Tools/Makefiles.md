# MAKE

> The hard work you don't see

You can find examples in the [Make Folder](Make)
Makefiles are recepies. Basically you just define:
| type | |
| --- | --- |
| variables | short names for commands and files |
| rules | how to do it, which input/output to use |
| targets | recepy-name (all when not specified)|

### Variables
There are many conventions on naming them.
As an example we would call TARGET the name of the final result, eg. executable\
`TARGET = progname`

You recall it by putting \&() around the name like\
`$(TARGET)`

If you define the compiler variable to be CC\
you could do so to compile and build your program
```
CC = gcc
$(CC) <source.c> -o $(TARGET)
```

A simple Makefile cold just be:
```
TARGET = testing_C
CC = gcc
all:
< TAB-8 > $(CC) <source.c> -o $(TARGET)
```
where < TAB-8 > is a real size 8 tab. ⚠️ not 8 spaces. this has to be set in your editor\
`:set noexpandtab` `set softtabstop=8` and `:set ts=8` in vim

You can make it permanent to your file:\
On the first line of Makefile write the following _vim_modeline_:

`vim: noexpandtab: ts=8: softtabstop=8`

> At this point, when you type `make`\
> You will get `testing_C` in the current folder.
