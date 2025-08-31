#include <iostream>
using namespace std;

int rows, cols, nonZero1, nonZero2;
int mat1[50][3];
int mat2[50][3];
int result[50][3];

void matrix_input(int arr[50][3], int &nonZero) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> nonZero;
    arr[0][0] = rows;
    arr[0][1] = cols;
    arr[0][2] = nonZero;
    for (int i = 1; i <= nonZero; i++) {
       cout << "Enter row index: ";
       cin >> arr[i][0];
       cout << "Enter col index: ";
       cin >> arr[i][1];
       cout << "Enter value: ";
       cin >> arr[i][2];
    }
}

void result_matrix(int a[50][3], int n1, int b[50][3], int n2) {
    result[0][0] = rows;
    result[0][1] = cols;
    int i=1, j=1, k=1;
    while (i <= n1 || j <= n2) {
        if (j > n2 || (i <= n1 && (a[i][0] < b[j][0] || (a[i][0]==b[j][0] && a[i][1] < b[j][1]))))
            result[k][0]=a[i][0], result[k][1]=a[i][1], result[k][2]=a[i][2], i++;
        else if (i > n1 || (b[j][0] < a[i][0] || (b[j][0]==a[i][0] && b[j][1] < a[i][1])))
            result[k][0]=b[j][0], result[k][1]=b[j][1], result[k][2]=b[j][2], j++;
        else
            result[k][0]=a[i][0], result[k][1]=a[i][1], result[k][2]=a[i][2]+b[j][2], i++, j++;
        k++;
    }
    result[0][2] = k-1;
}

void display_matrix(int arr[50][3]) {
    int total = arr[0][2];
    for (int i = 0; i <= total; i++) {
       cout << arr[i][0] << " "
                  << arr[i][1] << " "
                  << arr[i][2] << "\n";
    }
}

int main() {
    cout << "First matrix:\n";
    matrix_input(mat1, nonZero1);
    cout << "Second matrix:\n";
    matrix_input(mat2, nonZero2);
    result_matrix(mat1, nonZero1, mat2, nonZero2);
    cout << "Result matrix:\n";
    display_matrix(result);
}
