#include<iostream>
#include<stdlib.h>
#include<fstream>

void populateFile(int count,
                  std::string const& file)
{
    std::ofstream myfile(file);
    if (!myfile )
    {
       // Deal with error.
       return;
    }

    for(int index=0; index<count; index++)
    {
        float random_integer = rand();
        myfile << random_integer << "\n";
    }
}


int main()
{
   // Seed the random number generator.
   srand(42);

   // Populate the file
   std::string file("Random_cpp.txt");
   populateFile(1000, file);
   return 0;
}