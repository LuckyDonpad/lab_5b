//
// Created by Donpad on 27.01.2022.
//
#include <stdio.h>
#include "matrix.h"
#include <malloc.h>
#include <assert.h>
#include "array.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix mat) {
    for (size_t i = 0; i < mat.nRows; ++i)
        free(mat.values[i]);
    free(mat.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    assert(nMatrices > 0);

    for (size_t i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int row = 0; row < m.nRows; ++row)
        for (int column = 0; column < m.nCols; ++column)
            scanf("%d", &(m.values[row][column]));
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int matrix = 0; matrix < nMatrices; ++matrix) {
        inputMatrix(ms[matrix]);
    }
}

void outputMatrix(matrix m) {
    for (int row = 0; row < m.nRows; ++row) {
        printf("\n| ");
        for (int column = 0; column < m.nCols; ++column) {
            printf("%d | ", (m.values[row][column]));
        }
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int matrix = 0; matrix < nMatrices; ++matrix) {
        outputMatrix(ms[matrix]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *tmp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = tmp;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int row = 0; row < m.nRows; ++row) {
        swap_(&m.values[row][j1], &m.values[row][j2], sizeof(int));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArray[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        int max = i;
        for (int j = i; j < m.nRows; j++) {
            if (criteriaArray[j] > criteriaArray[max])
                max = j;
        }
        printf("%lld\n", sizeof(&criteriaArray[max]));
        printf("%lld\n", sizeof(int *));
        swap_(&criteriaArray[max], &criteriaArray[i], sizeof(int));
        swapRows(m, i, max);
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
}

bool isSquareMatrix(matrix m) {
    return (bool) m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        bool isEqual = true;
        size_t y = 0;
        while (isEqual && y < m1.nRows) {
            size_t x = 0;
            while (isEqual && x < m1.nCols) {
                isEqual = (bool) (m1.values[y][x] == m2.values[y][x]);
                x++;
            }
            y++;
        }
        return (bool) isEqual;
    }
    return (bool) false;
}

bool isEMatrix(matrix m) {
    bool isE = true;
    size_t y = 0;
    while (isE && y < m.nRows) {
        size_t x = 0;
        while (isE && x < m.nCols) {
            isE = (bool) (m.values[y][x] == 1);
            x++;
        }
        y++;
    }
    return (bool) isE;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        return false;
    } else {
        bool isSymmetric = true;
        size_t y = 0;
        while (isSymmetric && y < m.nRows) {
            size_t x = 0;
            while (isSymmetric && x < m.nCols) {
                isSymmetric = (bool) (m.values[y][x] == m.values[x][y]);
                x++;
            }
            y++;
        }
        return (bool) isSymmetric;
    }
}