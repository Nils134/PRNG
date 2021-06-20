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
int fd1;
int fd2;
int i = 0;
int x = 0;
float reserve[100];

int  getSubString(char *source, char *target,int from, int to)
{
	int length=0;
	int i=0,j=0;
	// printf("Test srouce %s\n", source);
	//get length
	while(source[i++]!='\0') 
		length++;


	// printf("length %d\n", length);
	if(from<0 || from>length){
		printf("Invalid \'from\' index, from = %d, length = %d\n", from, length);
		return 1;
	}
	if(to>length){
		printf("Invalid \'to\' index, to = %d \n, length = %d", to, length);
		return 1;
	}	
	
    // printf("Converting\n");
	for(i=from,j=0;i<=to;i++,j++){
		target[j]=source[i];
	}
	
	//assign NULL at the end of string
	target[j]='\0'; 
	
	return 0;	

}

double getNumber() {
    // printf("Getting nuber\n");
    char * str1 = (char*)calloc(1501*sizeof(char), sizeof(char));

    while(1) {
        
        if (i < x) {
            float result = reserve[i];
            i++;
            // printf("%f\n", result);
            free(str1);
            return result;
        }
        else { 

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
            char * str2 = (char*)calloc(16*sizeof(char), sizeof(char));
            int reading = read(fd1,str1, 1500);
            // printf("reading = %d\n", reading);
            // printf("%c testing \n", str1[1]);
            i = 0;
            x=0;
            for (int j = 0; j < reading -1; j=j+15) {
                // printf("%d\n", j);
                getSubString(str1,str2,j, j+14);
                // printf("str2 %s\n", str2);
                float temp = strtod(str2,NULL);
                // printf("%.12f temp\n", temp);
                reserve[x] =temp;
                x++;
                
            }
            if (x == 0) {
                printf("array not filled");
            }
            free(str2);
        }
        else {
            // printf("No data within five seconds.\n");
            char * test = "hello\n";
            write(fd2, test, sizeof(test));
            sleep(1);
            // printf("Not finding new numbers, retval %d \n", retval);
        }
        }
        
    }

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
    bbattery_SmallCrush(gen);
    printf("Done, \n");
    close(fd2);
    close(fd1);
    return 0;
}