#include <iostream>

#include "Contador.h"
using namespace std;
int main() {
    Contador i(5),s;

    std::cout  << i<<std::endl;

    s=++i;
    ++s;

    std::cout << s<<endl;
    std::cout <<s++;
    return 0;

}