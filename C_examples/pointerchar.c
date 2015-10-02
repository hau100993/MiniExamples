#include <stdio.h>
#include <string.h>



 void main () {


  char *a ;
  char b[10];
  char c[10];
  
  a = "abc" ;
  strcpy(b, "12345");
  
printf ("string a  %s \n " , a) ;
printf ("string b 1  %s \n " , b) ;
b[0]='\0' ;
a="" ;
strcpy (c, a);
printf ("string c 2 %s \n " , c) ;

}


