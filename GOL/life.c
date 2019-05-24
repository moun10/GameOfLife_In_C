#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//NOTE  gcc -Wall -std=c99 -o main *.c -> ./main first.gol
/*
 *  By N/A
 */

 /*
  * Gets the grid and allocates memory
  * Returns the grid
  */
char** get_grid(int x, int y){
  //Space + 2 for the first two bits, (size x size)
    int allN = ((x*y) + 2);
  //Allocates Memory
    char **grid = (char**) malloc(sizeof(char) * allN);
    for( int a = 0; a <= x; a++ )
    {
      //go through grid array pointers
      grid[a] = (char*) malloc(sizeof(char) * y);
    }
    //return grid
    return grid;
  }

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid) {
  //Print space to make it look good
	printf("\n");

  //Array For looping through pointer array
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
      //Checks If Not Null, Not Empty
      if(((int)grid[i][j] + (int)grid[i][j]) != 0){
        printf("%hhx",1);
      }else{
        //Print Zero If Empty or Null
        printf("%hhx",0);
      }
		}
		printf("\n");
	}

	printf("\n");

  }

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid) {
    /* NOTE
    - A live cell with less than two live neighbors dies
    - A live cell with two or three live neighbors lives
    - A live cell with more than three neighbors dies
    - A dead cell with three live neighbors becomes live
    * - From CIS 343 Project Guide, GVSU
    */
    //Create New Array
    char **mutgrid = get_grid(x,y);

    //Loops Through Pointer Array
    for (int a = 0; a < x ; a++)
    {
        for (int b = 0; b < y; b++)
        {

          //Calls Get Neighbors Function
          //Switch Case To Neighbors Number
            switch(get_neighbors(a,b,x,y,grid))
            {
                // cell with 2 live neighbors, no change for live or dead
                case 2:
                  if(((int)grid[a][b] + (int)grid[a][b]) != 0){
                    mutgrid[a][b] = (char) 1;
                  } else{
                    mutgrid[a][b] = (char) 0;
                  }
                    break;
                case 3:
                    mutgrid[a][b] = (char) 1;
                    break;

                    // any other result is dead cell
                default:
                    mutgrid[a][b] = (char) 0;
            }
        }
    }

    //Returns Mutated Grid, Original Grid is Not Changed
    return mutgrid;
    }

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 * i,j are coordinates
 */
int get_neighbors(int i, int j, int x, int y, char** grid){
    //NOTE Return -1 if cell out of boundary

    //Counter For Neighbors
    int counter = 0;

    //Checks if eighbor Exits, Up, Down, Left, and Right
            if(i != x) {
              if((int)grid[i+1][j] - 0 != 0){
                counter++;
              }
            }
            if (i != 0) {
              if((int)grid[i-1][j] - 0 != 0){
                counter++;
            }
          }
            if(j != y) {
              if((int)grid[i][j+1] - 0 != 0){
                counter++;
            }
          }
            if(j != 0) {
              if((int)grid[i][j-1] - 0 != 0){
                counter++;
            }
        }
    //Returns Number of Live Neighbors
    return  counter;
}
