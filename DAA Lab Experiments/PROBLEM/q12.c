//12) Count Nonzero Elements in 2D Array
#include <stdio.h>
int countNonZero(int matrix[3][3], int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
    }
    return count;
}

int main() {
    int matrix[3][3] = {{1, 0, 2}, {0, 3, 0}, {4, 5, 6}};
    printf("Number of nonzero elements: %d\n", countNonZero(matrix, 3, 3));
    return 0;
}
