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

//освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m с клавиатуры,
void inputMatrix(matrix m);

// ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m на экран
void outputMatrix(matrix m);

// вывод массива матриц ms размера nMatrices на экран
void outputMatrices(matrix *ms, int nMatrices);

// обменивает местами строки матрицы m под номерами i1 и i2
void swapRows(matrix m, int i1, int i2);

// обменивает местами колонки матрицы m под номерами j1 и j2
void swapColumns(matrix m, int j1, int j2);

//выполняет сортировку вставками строк
//матрицы m по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

#endif //LAB_5B_MATRIX_H
