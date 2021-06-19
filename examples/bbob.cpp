
#include "/usr/local/include/ioh/common/random.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <iterator>
#include <algorithm>


int main() {
    ioh::common::random::lcg_rand(42);
    while(1) {
        std::string n;
        std::cin >> n;
        std::vector<double> temp = ioh::common::random::uniform(1000000, 42);
        for(int i = 0; i < 100; i++) {
            printf("%.12f\n", temp[i]);
            }
        }
    return 0;
}