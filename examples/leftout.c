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
#include "sstring.h"
#include <stdlib.h>
#include <poll.h>

#include <sys/time.h>
#include <sys/types.h>
int fd1;
int fd2;


double getNumber() {
    // printf("Getting nuber\n");
    char str1[15] = "\0";

    while(1) {
        
        fd_set rfds;
        struct timeval tv;
        int retval;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&rfds);
        FD_SET(fd1, &rfds);
        /* Wait up to five seconds. */
        tv.tv_sec = 0;
        tv.tv_usec = 1000;
        retval = select(fd1+1, &rfds, NULL, NULL, &tv);
        /* Don’t rely on the value of tv now! */

        if (retval == -1)
            perror("select()");
        else if (retval) {
            
            read(fd1,str1, 15);
            // printf("Test number %s\n", str1);
            str1[15] = '\0';
            
            // printf("Data is available now: %s\n", str1);
            break;
            /* FD_ISSET(0, &rfds) will be true. */
        }
        else {
            // printf("No data within five seconds.\n");
            char * test = "hello\n";
            write(fd2, test, sizeof(test));
            // printf("Not finding new numbers, retval %d \n", retval);
        }
        
    }


    double result = strtod(str1, NULL);
    // if (result > 1) {
    //     printf("Failuree");
    // }
    // Print the read string and close
    // printf("Var is now: %f\n", result);
    return result;
}


int main(void)
{
    printf("Start\n");
    char * request = "emptyPipe";
    char * receive = "randomPipe";
    fflush(NULL);
    fd2 = open(request, O_WRONLY | O_NONBLOCK);
    if (fd2 == -1) {
        printf("File request not opened correctly\n");
        
    }
    fd1 = open(receive, O_RDONLY| O_NONBLOCK);
    if (fd1 == -1) {
        printf("File receive not opened correctly\n");
    }
    
    unif01_Gen *gen = unif01_CreateExternGen01("test", getNumber);
    gen->GetU01(gen->param, gen->state);
    sstring_HammingCorr(gen, NULL, 1, 10000000,  0,30,1200 );
    sstring_HammingIndep(gen, NULL, 1, 300000000, 0, 30, 30 ,0);
    sstring_HammingIndep(gen, NULL, 1, 100000000, 20,10,30,0);
    sstring_HammingIndep(gen, NULL, 1, 30000000, 0 ,30, 300, 0);
    sstring_HammingIndep(gen, NULL, 1, 10000000, 0, 30, 300,0);
    sstring_HammingIndep(gen, NULL, 1, 10000000, 20, 10, 300, 0);
    sstring_HammingIndep(gen, NULL, 1,10000000, 20, 10, 300, 0);
    sstring_HammingIndep(gen, NULL, 1,1000000, 20, 10, 1200, 0);
    sstring_Run(gen, NULL,1, 1000000000, 0, 30);
    sstring_Run(gen, NULL, 1, 1000000000, 20, 10);
    sstring_AutoCor(gen, NULL, 10, 1000000000, 0, 30, 1);
    sstring_AutoCor(gen, NULL, 5, 1000000000, 20, 10, 1);
    sstring_AutoCor(gen, NULL, 10, 1000000000, 0, 30, 30);
    sstring_AutoCor(gen, NULL, 5, 1000000000, 20, 10, 10);    
    printf("Done, \n");
    close(fd2);
    close(fd1);
    return 0;
}