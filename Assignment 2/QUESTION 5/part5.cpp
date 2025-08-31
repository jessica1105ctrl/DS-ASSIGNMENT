#include <iostream>
using namespace std;
const int size = 4;

int main() {
    int i, j, k = 0;
    int total = (size * (size + 1)) / 2;  
    int Array[total];

    cout << "Enter elements (row major lower triangle)\n";
    for (i = 0; i < total; i++) {
        cin >> Array[i];
    }

    cout << "The symmetric matrix is:\n";
    k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i >= j) {
                
                cout << Array[k] << " ";
                k++;
            } else {
             
                int index = (j * (j + 1)) / 2 + i;  
                cout << Array[index] << " ";
            }
        }
        cout << "\n";
    }
}
