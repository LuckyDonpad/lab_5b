//
// Created by Donpad on 27.01.2022.
//

#ifndef LAB_5B_MATRIX_H
#define LAB_5B_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// возвращает матрицу в nRows строк и nCols столбцов, размещенную в динамической памяти
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из nMatrices матриц размером
// nRows строк на nCols столбцов. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память выделеную под хранение матрицы mat
void freeMemMatrix(matrix mat);



#endif //LAB_5B_MATRIX_H
