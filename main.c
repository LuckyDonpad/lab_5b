#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int arraySum(int *array, size_t size){
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int a = 4;
    int b = 2;
    matrix matrix1 = getMemMatrix(3, 3);
    inputMatrix(matrix1);
    insertionSortRowsMatrixByRowCriteria(matrix1, (int (*)(int *, int)) arraySum);
    outputMatrix(matrix1);
    return 0;
}
