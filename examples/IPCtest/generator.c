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
#include <poll.h>
int fd2;


double getNumber() {
    
    char str1[20] = "\0";
    int ret_poll;
    struct pollfd input[1] = {{fd: 0, events: POLLIN}};
    while(1) {
        fflush(stdout);
        ret_poll = poll(input, 1, 10);
        if (ret_poll >0 ) {
            fgets(str1, 20, stdin);
            break;
        }
        else {
            char * test = "hello\n";
            write(fd2, test, sizeof(test));
        }
    }
    
    double result = strtod(str1, NULL);
    // Print the read string and close
    // printf("Var is now: %f\n", result);
    return result;
}


int main()
{
    char * request = "emptyPipe";
    fd2 = open(request, O_WRONLY);
    unif01_Gen *gen = unif01_CreateExternGen01("test", getNumber);
    gen->GetU01(gen->param, gen->state);
    bbattery_SmallCrush (gen);
    printf("Done, \n");
    return 0;
}