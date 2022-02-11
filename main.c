#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/array.h"

void test_twoMatricesEqual_equalMatrices();

void test_twoMatricesEqual_nonEqualMatricesByValue();

void test_twoMatricesEqual_nonEqualMatricesBySize();

int arraySum(int *array, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

int main() {

    matrix matrix1 = getMemMatrix(3, 3);

    inputMatrix(matrix1);

    insertionSortColsMatrixByColCriteria(matrix1, arraySum);
    outputMatrix(matrix1);
    return 0;
}
