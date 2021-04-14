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

double getNumber(char* myfifo) {
    char str1[80];
    int fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);
        double result = strtod(str1, NULL);
        // Print the read string and close
        close(fd1);
  
        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo,O_WRONLY);
        int random = 1;
        char output[] = "Test";

        write(fd1, output, strlen(output)+1);
        close(fd1);
    return result;
}


int main()
{
    int fd1;
  
    // FIFO file path
    char * myfifo = "pipe";
  
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);
    srand(42);
    char str1[80];
    double random = 1;
    for(int i= 0; i < 10; i++) {
        printf("Python returned %f\n", getNumber(myfifo));
    }
    return 0;
}