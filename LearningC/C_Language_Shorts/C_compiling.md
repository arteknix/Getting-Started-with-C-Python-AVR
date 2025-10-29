# Compiling and Building

In a very simplistic manner,
- compiling is turning text into objects
- building is linking objects to create the executable

gcc handels all this for you.

We will see how to customize this with makefiles


## Simple Form
`gcc <sourcefile.c> -o <programname>`
> if you use the minimal.c example, this could be:
>
> `gcc minimal.c -o minimal_C_prog`
> 

## Short Form
`gcc <sourcefile.c>`

⚠️ The resulting executable will be named a.out

## With Object Files (.o)
```
gcc -c <sourcefile.c> -o <sourcefile.o>
gcc <sourcefile.o> -o <programname>

```
# Makefiles

[makefiles](../../Tools/Makefiles.md)
