#include <iostream>
const int size = 4;

int main() {
    int i, j, k = 0;
    int total = (size * (size + 1)) / 2;  
    int Array[total];

    std::cout << "Enter elements (row major lower triangle)\n";
    for (i = 0; i < total; i++) {
        std::cin >> Array[i];
    }

    std::cout << "The lower triangular matrix is:\n";
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i >= j) {std::cout << Array[k] << " ";
                k++;
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }
}
