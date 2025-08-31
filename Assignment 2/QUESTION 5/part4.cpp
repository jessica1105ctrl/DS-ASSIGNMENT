#include <iostream>
using namespace std;
const int size = 4;

int main() {
    int i, j, k = 0;
    int total = (size * (size + 1)) / 2;  
    int Array[total];

    std::cout << "Enter elements (row major upper triangle)\n";
    for (i = 0; i < total; i++) {
        cin >> Array[i];
    }

   cout << "The upper triangular matrix is:\n";
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i <= j) {   std::cout << Array[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}
