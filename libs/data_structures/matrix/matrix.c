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

void swapColumns(matrix m, int j1, int j2){
    for (int i = 0; i < ; ++i) {
        
    }
}