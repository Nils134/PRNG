# Testing the performance of popular programming languages using Testu01
## Installation of Testu01
A complete tutorial on how to install the Testu01 test suite can be found here: http://simul.iro.umontreal.ca/testu01/tu01.html.
The required files can also be found here. 

For linux users (Bash):
With a Bash shell, a user need to use the following commands (within the Testu01 directory):
./configure
make
make install

alternative suggestions for an install directory:

./configure --prefix=<install directory>
make
make install

To compile programs, we need to add the environment variables with the following commands:
LD_LIBRARY_PATH    <install directory>/lib
LIBRARY_PATH       <install directory>/lib
C_INCLUDE_PATH     <install directory>/include

Since the default commands would send my installment to usr/local/bin, I used within the Testu01 directory:
export LIBRARY_PATH="/usr/local/lib:${LIBRARY_PATH}"
export C_INCLUDE_PATH="/usr/local/include:${C_INCLUDE_PATH}"
export LD_LIBRARY_PATH="/usr/local/lib:${LD_LIBRARY_PATH}"

If the installment was done correctly, we can compile with the Testu01 test suite using:
gcc tester.c -o tester -ltestu01 -lprobdist -lmylib -lm

Where tester.c contains some reference to the Testu01 library.

## Use 
I have defined 3 files for testing: Smalltester.c, Mediumtester.c, and Bigtester.c. These perform the SmallCrush, Crush and BigCrush respectively, as described within the Testu01 paper. This paper can be found at the link at the top of the description. Since we want to test a wide array of programming languages, we will use named pipes. Named pipes are FIFO systems, based on the pipes used in Bash commands. They allow great throughput, which we need to manage vast amounts of numbers. With these named pipes, we are able to connect a file with a generator, if the generator can read from the standard input and write to the standard output. Named pipes can be generated using the mkfifo command. More information about the mkfifo command can be found here: https://linux.die.net/man/3/mkfifo. 

In my program, I use two random pipes, called randomPipe and emptyPipe. These can be generated by mkfifo randomPipe and mkfifo emptyPipe. EmptyPipe will serve as a channel for the tester programs to request more numbers from the generator. These will be read in by the generator program via the stdin. After this, the generator will start to send out numbers via the stdout, which will be directed to randomPipe. The tester program will read numbers from this named pipe until it is exhausted, after which the program continues. 

The generator program can be connected to this pipes via ./program < emptyPipe > randomPipe . After this, we can run the tester program by running one of the compiled test files. Eg. ./tester that was previously generated.

## Running different programming languages

C#: install monocomplete
Java: install jre and jdk
Javascript: install node
R: use Rscript to run R via terminal
C++: g++ compiler
C: gcc compiler
C#: Monocomplete
Java: JDK and JRE
Fortran: gfortran
PHP: php cli 
Bash:
