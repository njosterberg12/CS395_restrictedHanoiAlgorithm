/***********************************************************************************************
 * Id: oste1799
 * Purpose:
 *  The following program has an algorithm that solves the Towers of Hanoi puzzle recursively
 * Input:
 *  ./assignment5 n            where n is the number of disks on peg A
 * Output:
 *  ex. Move A TO B
 *      Move B TO C
 *      ... etc.
 * Compile:
 *  gcc -Wall -o assignment5 assignment5.c
 *
 *********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void recursiveTower(int, char, char, char);
int main(int argc, char *argv[]){
   int numOfDisks = atoi(argv[1]); // number of disks on peg A
   if (argc > 2) // reject if too many args
   {
      printf("Usage: %s [number of disks] <element n>*\n", argv[0]);
      printf("Example: %s 5 represents 5 disks on peg A to be moved to peg C.\n", argv[0]);
      return 0;
   }
   if (argc < 2) // reject if not enough args
   {
      printf("Choose a disk number");
      return 0;
   }
   recursiveTower(numOfDisks,'A','C','B');
   return 0;
}
// this function moves disks from A to C recursively
void recursiveTower(int numOfDisks, char fromRod, char toRod, char midRod)
{
   if (numOfDisks > 0)
   {
      recursiveTower(numOfDisks - 1, fromRod, toRod, midRod);
      printf("Move %c TO %c\n", fromRod, midRod); // prints from first rod to temp middle rod
      recursiveTower(numOfDisks-1, toRod, fromRod, midRod);
      printf("Move %c to %c\n", midRod, toRod); // prints from temp middle rod to destination rod
      recursiveTower(numOfDisks-1, fromRod, toRod, midRod);
   }
}