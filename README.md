# Game of Life C

The Game of Life coded in C. It can be described as a 'cellular automaton' game, and was devised by Cambridge mathematician John Conway. The game consists of a collection of cells which, based on a few mathematical rules, can live,die or multiply.

[![Trump2Cash](https://proxy.duckduckgo.com/iu/?u=https%3A%2F%2Fimage.slidesharecdn.com%2Fartificiallife-101014042202-phpapp02%2F95%2Fartificial-life-2005-34-728.jpg%3Fcb%3D1287030482&f=1&nofb=1)](https://trump2cash.biz)

The code is written in C and is meant to run on a
Linux based machine.

The [`life.c`](life.c) file will execute the game rules and define the math for each automation.

```C
// life.c
char** mutate(int x, int y, char** grid) {
    /* NOTE
    - A live cell with less than two live neighbors dies
    - A live cell with two or three live neighbors lives
    - A live cell with more than three neighbors dies
    - A dead cell with three live neighbors becomes live
    * - From CIS 343 Project Guide, GVSU
    */
```

Follow these steps to run the code yourself:

### 1. Download GCC Compiler

```shell
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
$ sudo apt-get install gcc
```

### 2. Check Version

```shell
$ whereis gcc make
$ gcc --version
$ make -v
```


### 3. Run the main file

```shell
$ gcc -Wall -std=c99 -o main *.c 
$ ./main first.gol
```



## License

Copyright 2019 Harman Rai
Template GVSU

