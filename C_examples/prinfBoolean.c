#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (!FALSE)
#endif


void  event_set_led(unsigned int ledid, unsigned int on) {
printf(" LED : %d , %s \n", ledid, (on)? "ON":"OFF");

}

typedef enum {	
blue	=1,
red	=2,
yellow	=3,
} led_color ;

void main () {
 led_color led;
 led = blue;
event_set_led(led, TRUE);
printf ("  Done !\n" );

}










