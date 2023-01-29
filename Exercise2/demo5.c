#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 50 */
 
    printf("Test");

   /* Print 5 random numbers from 0 to 50 */
   
   
    printf("\n-%d\n", (rand() % 200) - 100);
   
   
   
   
   return(0);
}

