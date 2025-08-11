#include <iostream>
using namespace std;

int size;
int Array[50];
int m1[2][2], m2[2][2], result[2][2];

void display_array(){
    for(int i=0;i<size;i++){
        cout << Array[i] << "\n";
    }
}

void reverse_array(){
    for(int i=0;i<size/2;i++){
        int temp = Array[i];
        Array[i] = Array[size-i-1];
        Array[size-i-1] = temp;
    }
}

void multiply_matrices(){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            result[i][j]=0;
            for(int k=0;k<2;k++){
                result[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    cout << "Multiplication result:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

void transpose_matrix(){
    int transpose[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            transpose[j][i] = m1[i][j];
        }
    }
    cout << "Transpose of first matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << transpose[i][j] << " ";
        }
        cout << "\n";

int main(){


   cout << "Enter size of array: ";
    cin >> size;
    for(int i=0;i<size;i++){
        cin >> Array[i];
    }
    reverse_array();
    display_array();

    cout << "Enter the first 2x2 matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> m1[i][j];
        }
    }
    cout << "Enter the second 2x2 matrix:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> m2[i][j];
        }
    }
    multiply_matrices();
    transpose_matrix();
}

