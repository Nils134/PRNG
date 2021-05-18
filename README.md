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



