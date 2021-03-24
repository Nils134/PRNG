#include <stdio.h>
extern float number();

float cpp_PRNG() {
    return number();
}


int main (void) {
    for(int i = 0; i < 5; i++) {
        printf("Number %d was %f", i, cpp_PRNG());
    }
}