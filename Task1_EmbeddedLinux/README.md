# How to create a static Library and a dynamic library?

Steps: 

- [ ] -touch main.c
- [ ] -Create a directory named Includes (It has the includes .h files)
- [ ] -Create a file for each header to hold func parameter
- [ ] -in this task we will use [add.h sub.h multi.h div.h mod.h]
- [ ] -Create a directory named Lib (It has the source .c files)
- [ ] -Create a file for each source code of func
- [ ] -in this task we will use [add.c sub.c multi.c div.c mod.c]
- [ ] -CD Lib

## 1- Static Library :

1- Compile the source files using your compiler without linking, this step should get the obj files 

```
gcc -c *.c 
```

> - gcc : the compiler I am using
> - -c : flag tells the compiler to generate object files (.o) from the source files (.c) without linking them. Object files contain compiled code but are not yet executable.
> - (*.c) : this is a wildcard that specifies all C source files (*.c) in the current directory.



2- Creating Static Library (its name operation) using the object files :

```
ar -rcs liboperation.a *.o 
```

> - ar : archive command to create archive file.
> -  r : insert or replace the object file if exist to the archive .   
> - 
>   c : create the archive file if not exist.
> - s : add symbol table to the archive.
> - libName.a : the static library file,    lib for standard , Name is the name of static library, a stand for any static library)
> - (*.o) : this is a wildcard that specifies all object files (*.o) in the current directory.

3- cd and Link the static library with the main

```
gcc -static main.c -o Calculator -loperation -L ./Lib -I ./Include
```

> - static flag : to linking the library statically (we must use this flag because libraries linked dynamically by default .
> - -o Calculator : the name of executable output.
> - -l(L small) : specify the name of your library after l flag without the prefix "lib" and postfix "".a".
> - -L flag : specify the path of the function source files of the library.
> - -I ( capital) : specify the path of the header files of the library. 

4- Run the executable 

```
./Calculator 
```

5- In case you want to see the file type 

```
file Calculator 
```



![Screenshot from 2024-01-20 07-12-48](https://github.com/alaaelgammall/Embedded_Linux_repo/assets/100001810/b3e1872c-4dff-432c-aa32-797d86e99ae1)

## 2- Dynamic Library

1- Compile the source files using your compiler without linking, this step should get the obj files 
	

```
 gcc -c -fPIC *.c 
```

> gcc : the compiler I am using
>
> -c : flag tells the compiler to generate object files (.o) from the source files (.c) without linking them. Object files contain compiled code but are not yet executable.
>
> (*.c) : this is a wildcard that specifies all C source files (*.c) in the current directory.
>
> PIC : Position Independent Code flag is a compiler options that generate code suitable for use in shared libraries ,PIC is a feature that allows a compiled library to be loaded into memory at any address. This is essential for shared libraries because the exact memory location where a library is loaded can vary between different programs and is determined at run time. 
> 	

2- create the dynamic library 

```
gcc -shared -o liboperation.so *.o
```

> shared  : this option tells the linker to generate shared library instead of executable file.
>
> o flag : to specify the name of the library.
>
>  lib : postfix to follow the standard.
>
> operation : the name of the shared library.
>
> so : postfix stand for shared object .

3- You need to add the location of your dynamic library into the environmental variable 
<u>LD_LIBRARY_PATH</u> 
so the compiler knows where is the object codes of the functions you use.

```
export LD_LIBRARY_PATH= your/path/of/library
```

4- CD .. , and link the dynamiclibrary with main 

```
gcc main.c -o CalculatorDynamic -L ./Lib_Src -loperation -I ./includes
```

4- Run application

```
./CalculatorDynamic 
```

5- to show the symbol table of the shared library 

```
objdump -T liboperation.so  
```

![Screenshot from 2024-01-20 13-59-09](https://github.com/alaaelgammall/Embedded_Linux_repo/assets/100001810/32f8c781-2df8-43c6-8fe9-c8f04543d45f)
