#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define __FUNCTION__ (__func__)



 void printA ( int *c) 
 {
  printf (" %s() rev a value:  %d \n", __FUNCTION__,  *c);
}

void main () {

  int *c;
  int a =10;
  c = &a;
  *c = 15 ;
  printA((int*)a);
}
