#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

FILE *file ;
const char filepath[]= "/home/accedian/tmp/resuts.txt" ;

void main ()  {
unsigned int uint32  ;
unsigned long long int uint64 ;
uint64 = UINT_MAX +2;
uint32 = (unsigned int)uint64 ;
 //unsigned int a = uint32 ;


file = fopen(filepath, "wb") ;

fprintf (file, "Value of uint64  %llu  \n ", uint64 );
fprintf (file, "Value of uint32  %u    \n ", uint32 ) ;
fopen(filepath, "r") ;
printf( " Contents in file results %s : \n ", filepath) ;

fclose (file) ;

}
