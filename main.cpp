#include "to_far.h"
#include <iostream>
#include <random>

int main() {
    int celc;
    double dcelc;
    std::cout << "Input celc: ";
    std::cin >> celc;
    dcelc = celc;
    std::cout << normik::toFahrenheit<int, double>(celc) << std::endl;
    std::cout << randik::toFahrenheit<int, double>(celc) << std::endl;
    std::cout << normik::toFahrenheit<double, int>(dcelc) << std::endl;
    std::cout << randik::toFahrenheit<double, int>(dcelc) << std::endl;
    return 0;
}