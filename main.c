#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/array.h"
#include <assert.h>
#include <iso646.h>
#include "libs/data_structures/matrix/tasks.h"

int arraySum(int *array, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

void test_swapRows_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 0, 0, 0, 2, 2, 2}, 3, 3);
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 0 and m.values[0][1] == 0 and m.values[0][2] == 0 and
                   m.values[1][0] == 1 and m.values[1][1] == 1 and m.values[1][2] == 1);
}

void test_swapColumns_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {0, 1, 2, 0, 1, 2, 0, 1, 2}, 3, 3);
    swapColumns(m, 0, 1);
    assert(m.values[0][0] == 1 and m.values[1][0] == 1 and m.values[2][0] == 1 and
                   m.values[0][1] == 0 and m.values[1][1] == 0 and m.values[2][1] == 0);
}

void test_insertionSortRowsMatrixByRowCriteria_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 0, 0, 0, 2, 2, 2}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, arraySum);
    assert(arraySum(m.values[0], 3) >= arraySum(m.values[1], 3) and arraySum(m.values[1], 3) >=
                                                                    arraySum(m.values[2], 3));
}

void test_insertionSortColsMatrixByColCriteria_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    int col1[3], col2[3], col3[3];
    insertionSortColsMatrixByColCriteria(m, arraySum);
    getRowFromColumn(m, 0, col1);
    getRowFromColumn(m, 1, col2);
    getRowFromColumn(m, 2, col3);
    assert(arraySum(col1, 3) >= arraySum(col2, 3) and arraySum(col2, 3) >= arraySum(col3, 3));
}

void test_twoMatricesEqual_equalMatrices(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(twoMatricesEqual(m1,m2));
}

void test_twoMatricesEqual_nonEqualMatricesByValue(){
    matrix m1 = createMatrixFromArray((int[]) {0, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1,m2));
}

void test_twoMatricesEqual_nonEqualMatricesBySize(){
    matrix m1 = createMatrixFromArray((int[]) {0, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1,m2));
}


void test() {
    test_swapRows_smokeTest();
    test_swapColumns_smokeTest();
    test_insertionSortRowsMatrixByRowCriteria_smokeTest();
    test_insertionSortColsMatrixByColCriteria_smokeTest();
    test_twoMatricesEqual_equalMatrices();
    test_twoMatricesEqual_nonEqualMatricesBySize();
    test_twoMatricesEqual_nonEqualMatricesByValue();
}

int main() {
    test();

    return 0;
}
