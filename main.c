#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/array.h"
#include <assert.h>
#include <iso646.h>
#include "libs/data_structures/matrix/tasks.h"
#include <memory.h>


int arraySum(int *array, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}

void test_getMinInArea_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);
    int min = getMinInArea(m);
    assert(getMinInArea(m) == 5);
    freeMemMatrix(m);
}

void test_swapRows_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 0, 0, 0, 2, 2, 2}, 3, 3);
    swapRows(m, 0, 1);
    assert(m.values[0][0] == 0 and m.values[0][1] == 0 and m.values[0][2] == 0 and
                   m.values[1][0] == 1 and m.values[1][1] == 1 and m.values[1][2] == 1);
    freeMemMatrix(m);
}

void test_swapColumns_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {0, 1, 2, 0, 1, 2, 0, 1, 2}, 3, 3);
    swapColumns(m, 0, 1);
    assert(m.values[0][0] == 1 and m.values[1][0] == 1 and m.values[2][0] == 1 and
                   m.values[0][1] == 0 and m.values[1][1] == 0 and m.values[2][1] == 0);
    freeMemMatrix(m);
}

void test_selectionSortRowsMatrixByRowCriteria_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1, 0, 0, 0, 2, 2, 2}, 3, 3);
    selectionSortRowsMatrixByRowCriteria(m, arraySum);
    assert(arraySum(m.values[0], 3) <= arraySum(m.values[1], 3) and arraySum(m.values[1], 3) <=
                                                                    arraySum(m.values[2], 3));
    freeMemMatrix(m);
}

void test_selectionSortColsMatrixByColCriteria_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    int col1[3], col2[3], col3[3];
    selectionSortColsMatrixByColCriteria(m, arraySum);
    getRowFromColumn(m, 0, col1);
    getRowFromColumn(m, 1, col2);
    getRowFromColumn(m, 2, col3);
    assert(arraySum(col1, 3) <= arraySum(col2, 3) and arraySum(col2, 3) <= arraySum(col3, 3));
    freeMemMatrix(m);
}

void test_twoMatricesEqual_equalMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_nonEqualMatricesByValue() {
    matrix m1 = createMatrixFromArray((int[]) {0, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_nonEqualMatricesBySize() {
    matrix m1 = createMatrixFromArray((int[]) {0, 2, 3, 4}, 2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    assert(!twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_findSumOfMaxesOfPseudoDiagonal_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(m);

}

//TODO: переделать
void test_transposeIfMatrixHasEqualSumOfRows_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 3, 2,
                                              42, 42, 42,
                                              3, 2, 1}, 3, 3);
    matrix n = createMatrixFromArray((int[]) {1, 42, 3,
                                              3, 42, 2,
                                              2, 42, 1}, 3, 3);
    transposeIfMatrixHasEqualSumOfRows(m);
    assert(twoMatricesEqual(m, n));
    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test_getSquareOfMatrixIfSymmetric_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {2, 1, 2,
                                              1, 3, 0,
                                              2, 0, 3}, 3, 3);
    matrix n = createMatrixFromArray((int[]) {9, 5, 10,
                                              5, 10, 2,
                                              10, 2, 13}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(twoMatricesEqual(m, n));
    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test_sortByDistances_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {2, 1, 2,
                                              2, 0, 3,
                                              1, 3, 0,}, 3, 3);
    matrix n = createMatrixFromArray((int[]) {2, 1, 2,
                                              1, 3, 0,
                                              2, 0, 3}, 3, 3);

    sortByDistances(m);
    assert(twoMatricesEqual(m, n));
    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test_countEqClassesByRowsSum_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              1, 1, 1,
                                              2, 2, 2,
                                              2, 2, 2,
                                              2, 2, 2,
                                              3, 3, 3,
                                              3, 3, 3,
                                              4, 4, 4}, 8, 3);
    assert(countEqClassesByRowsSum(m) == 4);
    freeMemMatrix(m);
}

void test_getNSpecialElement_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 5,
                                              1, 1, 6,
                                              2, 2, 42,
                                              2, 2, 2,
                                              2, 2, 2,
                                              3, 3, 3,
                                              3, 3, 3,
                                              4, 4, 4}, 8, 3);
    int assertThis = getNSpecialElement(m);
    assert(assertThis == 3);
    freeMemMatrix(m);

}

void test_swapPenultimateRow_smokeTest() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);
    matrix n = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 4, 7,
                                              7, 8, 1}, 3, 3);
    swapPenultimateRow(m);
    assert(twoMatricesEqual(m, n));
    freeMemMatrix(m);
    freeMemMatrix(n);
}

void test() {
    test_swapRows_smokeTest();
    test_swapColumns_smokeTest();
    test_selectionSortRowsMatrixByRowCriteria_smokeTest();
    test_selectionSortColsMatrixByColCriteria_smokeTest();
    test_twoMatricesEqual_equalMatrices();
    test_twoMatricesEqual_nonEqualMatricesBySize();
    test_twoMatricesEqual_nonEqualMatricesByValue();
    test_getMinInArea_smokeTest();
    test_findSumOfMaxesOfPseudoDiagonal_smokeTest();
    test_transposeIfMatrixHasEqualSumOfRows_smokeTest();
    test_getSquareOfMatrixIfSymmetric_smokeTest();
    test_sortByDistances_smokeTest();
    test_countEqClassesByRowsSum_smokeTest();
    test_getNSpecialElement_smokeTest();
    test_swapPenultimateRow_smokeTest();
}

int main() {
    test();

    return 0;
}
