#include "unif01.h"
#include <stdio.h>
#include "bbattery.h"
#include <stdlib.h>

double generateNumber() {
    //printf("giving a number");
    return 0.0;
}

int main(void) {
    unif01_Gen *gen = unif01_CreateExternGen01("test", generateNumber);
    gen->GetU01(gen->param, gen->state);
    return 0;
}