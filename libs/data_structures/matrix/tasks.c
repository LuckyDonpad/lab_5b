//
// Created by Donpad on 14.02.2022.
//

#include "tasks.h"
#include "matrix.h"
#include <stddef.h>
#include "array.h"
#include <malloc.h>
#include <iso646.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

/// task 1
void swapRowsWithMinAndMax(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

/// task 2;
int getMaxNegative(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }

    return -max;
}

void sortRowsByMaxElement(matrix m) {
    selectionSortRowsMatrixByRowCriteria(m, getMax);
}

/// task 3
int getMinNegative(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}


void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

/// task 4
matrix mulMatrices(matrix m1, matrix m2) {
    matrix c = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            c.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                c.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return c;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        matrix z = mulMatrices(*m, *m);
        swap_(m, &z, sizeof(matrix));
        freeMemMatrix(z);
    }
}

/// task 5
void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long rowSums[m.nRows];
    for (int row = 0; row < m.nRows; ++row) {
        rowSums[row] = getSum(m.values[row], m.nCols);
    }
    if (!isUnique(rowSums, m.nRows))
        transposeSquareMatrix(m);
}

/// task 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m3 = mulMatrices(m1, m2);
    bool res = isEMatrix(m3);
    freeMemMatrix(m3);
    return res;
}


/// task 7
void getArrayFromLeftDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 and y != m.nCols) {
        array[*size] = m.values[x][y];
        *size += 1;
        y++;
        x--;
    }
}

int getDiagonalIndex(position pos, matrix m) {
    return abs(pos.rowIndex - pos.colIndex - (m.nRows - 1));
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int nDiagonals = m.nRows + m.nCols - 1;
    int diagonalMaxes[nDiagonals];
    for (int i = 0; i < nDiagonals; ++i) {
        diagonalMaxes[i] = INT32_MIN;
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position elementPos = {i, j};
            int element = getElementByPosition(m, elementPos);
            int diagonalIndex = getDiagonalIndex(elementPos, m);
            if (element > diagonalMaxes[diagonalIndex])
                diagonalMaxes[diagonalIndex] = element;
        }
    }
    return getSum(diagonalMaxes, nDiagonals) - diagonalMaxes[m.nRows - 1];
}

/// task 8
void getArrayFromRightDiagonal(matrix m, position pos, int *array, size_t *size) {
    *size = 0;
    int x = pos.rowIndex;
    int y = pos.colIndex;
    while (x >= 0 and y >= 0) {
        array[*size] = m.values[x][y];
        *size += 1;
        y--;
        x--;
    }
}

int getMinInArea(matrix m) {
    int diagonal[m.nCols];
    int size = 0;
    position max = getMaxValuePos(m);
    int x = max.rowIndex;
    int y = max.colIndex;
    int min = getElementByPosition(m, max);
    while (x != 0) {
        x--;
        getArrayFromLeftDiagonal(m, (position) {x, y}, diagonal, &size);
        int diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;

        getArrayFromRightDiagonal(m, (position) {x, y}, diagonal, &size);
        diagonalMin = getMin(diagonal, size);
        if (diagonalMin < min)
            min = diagonalMin;
    }
    return min;
}

/// task 9

float getDistance(int *a, int n) {
    float sumOfSquares = 0;
    for (int i = 0; i < n; ++i) {
        sumOfSquares += pow(a[i], 2);
    }
    return sqrtf(sumOfSquares);
}

void sortByDistances(matrix m) {
    selectionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

///task 10

int cmp_long_long(const void *pa, const void *pb) {
    if (*(long long *) pa == *(long long *) pb)
        return 0;
    else if (*(long long *) pa > *(long long *) pb)
        return 1;
    else
        return -1;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int uniqueElements = n > 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            uniqueElements++;
    }
    return uniqueElements;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        rowSums[i] = getSum(m.values[i], m.nCols);
    }
    int nClasses = countNUnique(rowSums, m.nRows);
    return nClasses;
}

/// task 11

int getNSpecialElement(matrix m) {
    int nSpecialElements = 0;
    for (int i = 0; i < m.nRows; ++i) {
        long long rowSum = getSum(m.values[i], m.nCols);
        long long max = getMax(m.values[i], m.nCols);
        nSpecialElements += rowSum - max < max;
    }
    return nSpecialElements;
}

/// task 12

void swapPenultimateRow(matrix m) {
    position minPos = getMinValuePos(m);
    int colWithMin[m.nRows];
    getRowFromColumn(m, minPos.colIndex, colWithMin);
    for (int i = 0; i < m.nRows; ++i) {
        m.values[m.nRows - 2][i] = colWithMin[i];
    }
}

/// task 13

bool isNonDescendingSorted(int *a, int n) {
    bool isSorted = true;
    size_t index = 1;
    while (isSorted and index < n) {
        isSorted = a[index] >= a[index - 1];
        index++;
    }
    return isSorted;
}

bool hasAllNonDescendingRows(matrix m) {
    bool isSorted = true;
    size_t index = 0;
    while (isSorted and index < m.nRows) {
        isSorted = isNonDescendingSorted(m.values[index], m.nCols);
        index++;
    }
    return isSorted;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nSorted = 0;
    for (int matrix = 0; matrix < nMatrix; ++matrix) {
        nSorted += hasAllNonDescendingRows(ms[matrix]);
    }
    return nSorted;
}