#include <iostream>
int rows1, cols1, nonZero1;
int rows2, cols2, nonZero2;
int mat1[50][3];
int mat2[50][3];
int result[50][3];

void matrix_input(int arr[50][3], int &rows, int &cols, int &nonZero) {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    std::cout << "Enter number of non-zero elements: ";
    std::cin >> nonZero;
    arr[0][0] = rows;
    arr[0][1] = cols;
    arr[0][2] = nonZero;
    for (int i = 1; i <= nonZero; i++) {
        std::cout << "Enter row index: ";
        std::cin >> arr[i][0];
        std::cout << "Enter col index: ";
        std::cin >> arr[i][1];
        std::cout << "Enter value: ";
        std::cin >> arr[i][2];
    }
}

void multiply_matrix() {
    if (cols1 != rows2) {
        std::cout << "Matrix multiplication not possible\n";
        result[0][2] = 0;
        return;
    }
    result[0][0] = rows1;
    result[0][1] = cols2;
    int k = 1;
    for (int i = 1; i <= nonZero1; i++) {
        for (int j = 1; j <= nonZero2; j++) {
            if (mat1[i][1] == mat2[j][0]) {
                int row = mat1[i][0];
                int col = mat2[j][1];
                int val = mat1[i][2] * mat2[j][2];
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == row && result[x][1] == col) {
                        result[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }
    result[0][2] = k-1;
}

void display_matrix(int arr[50][3]) {
    int total = arr[0][2];
    for (int i = 0; i <= total; i++) {
        std::cout << arr[i][0] << " "
                  << arr[i][1] << " "
                  << arr[i][2] << "\n";
    }
}

int main() {
    std::cout << "First matrix:\n";
    matrix_input(mat1, rows1, cols1, nonZero1);
    std::cout << "Second matrix:\n";
    matrix_input(mat2, rows2, cols2, nonZero2);
    multiply_matrix();
    std::cout << "Result matrix:\n";
    display_matrix(result);
}
