#include <stdio.h>
 
#define MACRO1(x) \
do{ unsigned i =0; \
    for (i=0; i<=x;i++) { \
    printf (" \n i[%d] = %d \n ", i, i); }} \
 while(0)

//#define marco2

int main () {

#ifdef MACRO1 
 printf ("MACRO1 is defined \n \a") ;
#else
printf ("MACRO1 is not defined \n \a");
#endif

#ifdef MACRO2
 printf ("MACRO2 is defined with value = %d \n \a", marco2) ;
#else
printf ("MACRO2 is not defined \n \a");
#endif
MACRO1(3);
return 0;
}
