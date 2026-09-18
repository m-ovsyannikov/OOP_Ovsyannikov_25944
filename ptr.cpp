#include <iostream>

int main() {
    int *ptr = {new int};
    delete ptr;
    ptr = nullptr;


    int *ptr1 = {new int[5] {1, 2, 3, 4, 5}};
    for(int idx=0; idx < 5; idx++) {
        std::cout << *(ptr1+idx) << ", ";
    }

}