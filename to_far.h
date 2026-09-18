#include <iostream>
#include <random>

namespace normik {
    template <typename in, typename out>
    out toFahrenheit (in &celc) {
            return (celc*1.8+32);
    }
}

namespace randik {
    template <typename in, typename out>
    out toFahrenheit (in &celc) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<>dist(0,255);
        if (dist(gen)%2 == 0) {
            return (celc*1.8+32);
        } else {
            return (celc*1.8+32 + gen());
        }
    }
}
