#include <iostream>
#include <fstream>
using namespace std;

int main() {
    srand(42);
    while(1) {
        string n;
        cin >> n;
        for(int i = 0; i < 1000000; i++) {
            double temp = ((double) rand() / (RAND_MAX));
            cout << temp << "\n";
            }
        }
    return 0;
}