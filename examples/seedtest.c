#include "unif01.h"
#include "ulcg.h"
#include "ulec.h"
#include <stdio.h>
#include "bbattery.h"
#include <stdlib.h>

//small test for checking if a generators fails for a given seed, it fails for multiple seeds
int main (void) 
{
   time_t t;
    /* Intializes random number generator */
   srand((unsigned) time(&t));

   unif01_Gen *gen;
   for (int i = 0; i < 50; i++) {
       int number = rand();
       printf("number for this test: %d", number);
        gen = ulcg_CreateLCG (2147483647, 16807, 0, number);
        bbattery_SmallCrush(gen);
        ulcg_DeleteGen (gen);
   }
   return 0;
}