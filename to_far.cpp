#include "to_far.h"
#include <random>
using namespace std;

float toFahrenheit (int celc) {
        return (celc*1.8+32);
}

float toFahrenheit_rand (int celc) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,255);
    if (dist(gen)%2 == 0) {
        return (celc*1.8+32);
    } else {
        return (celc*1.8+32 + gen());
    }
}
