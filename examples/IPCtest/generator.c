// C program to implement one side of FIFO
// This side reads first, then writes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include "unif01.h"
#include <stdio.h>
#include "bbattery.h"
#include <stdlib.h>

double getNumber() {
    char * myfifo = "randomPipe";
    char * request = "emptyPipe";
    char str1[80];
    int fd1 = open(myfifo,O_RDONLY);
    int test = read(fd1, str1, 80);
    if (test < 15) {
        printf("Too short: %d", test);
    }
    printf("%s\n", str1);
    double result = strtod(str1, NULL);
    // Print the read string and close
    close(fd1);

    return result;
}


int main()
{
    int fd1;
    // for(int i= 0; i < 10; i++) {
    //     printf("Python returned %f\n", getNumber(myfifo));
    // }
    sleep(10);
    unif01_Gen *gen = unif01_CreateExternGen01("test", getNumber);
    gen->GetU01(gen->param, gen->state);
    bbattery_SmallCrush (gen);
    return 0;
}