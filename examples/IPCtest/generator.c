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

#include <sys/time.h>
#include <sys/types.h>
int fd2;


double getNumber() {
    printf("Getting nuber\n");
    char str1[20] = "\0";

    // struct pollfd input[1] = {{fd: STDIN_FILENO, events: POLLIN}};
    while(1) {
        // fflush(stdout);
        // ret_poll = poll(input, 1, 1000);
        // if (ret_poll >0 ) {
        //     printf("Wroking %d",  ret_poll);
        //     fgets(str1, 20, stdin);
        //     break;
        // }
        // else {
        //     char * test = "hello\n";
        //     write(fd2, test, sizeof(test));
        //     printf("Not finding new numbers");
        // }
        
        fd_set rfds;
        struct timeval tv;
        int retval;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        /* Wait up to five seconds. */
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don’t rely on the value of tv now! */

        if (retval == -1)
            perror("select()");
        else if (retval) {
            
            fgets(str1, 20, stdin);
            printf("Data is available now: %s\n", str1);
            break;
            /* FD_ISSET(0, &rfds) will be true. */
        }
        else {
            // printf("No data within five seconds.\n");
            char * test = "hello\n";
            write(fd2, test, sizeof(test));
            printf("Not finding new numbers\n");
        }
    }
    double result = strtod(str1, NULL);
    // Print the read string and close
    // printf("Var is now: %f\n", result);
    return result;
}


int main(void)
{
    printf("Start\n");
    char * request = "emptyPipe";
    fflush(NULL);
    fd2 = open(request, O_WRONLY, O_NONBLOCK);
    if (fd2 == -1) {
        printf("File not opened correctly\n");
    }
    
    
    unif01_Gen *gen = unif01_CreateExternGen01("test", getNumber);
    gen->GetU01(gen->param, gen->state);
    bbattery_SmallCrush (gen);
    printf("Done, \n");
    close(fd2);
    return 0;
}