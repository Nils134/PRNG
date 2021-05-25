#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    srand(42);
    char temp[20];
    while(1) {
        fgets(temp, 20, stdin);
        for(int i = 0; i < 1000000; i++) {
            double tempfloat = ((double) rand() / (RAND_MAX));
            printf("%0.12f\n", tempfloat);
        }
    }
    return 0;
}