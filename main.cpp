#include "to_far.h"
#include <iostream>
#include <random>

int main() {
    int celc;
    int v;
    std::cout << "Choose version: 0 - without rand, 1 - with rand: ";
    std::cin >> v;
    std::cout << "Input celc: ";
    std::cin >> celc;
    if (v == 0) {
        std::cout << toFahrenheit(celc);
    } else {
        std::cout << toFahrenheit_rand(celc);
    }
    return 0;
}