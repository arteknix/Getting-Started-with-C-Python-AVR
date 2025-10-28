# Compiling and Building

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
