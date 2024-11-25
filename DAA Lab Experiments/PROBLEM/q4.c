//4) Sum of Rows and Columns of a Matrix
#include <stdio.h>

void sumRowsAndColumns(int matrix[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++)
            rowSum += matrix[i][j]; // Sum elements of the row
        printf("Sum of row %d: %d\n", i + 1, rowSum);
    }

    for (int j = 0; j < col; j++) {
        int colSum = 0;
        for (int i = 0; i < row; i++)
            colSum += matrix[i][j]; // Sum elements of the column
        printf("Sum of column %d: %d\n", j + 1, colSum);
    }
}

int main() {
    int matrix[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int row = 3, col = 3;

    sumRowsAndColumns(matrix, row, col);
    return 0;
}
