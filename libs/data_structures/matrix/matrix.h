//
// Created by Donpad on 27.01.2022.
//

#ifndef LAB_5B_MATRIX_H
#define LAB_5B_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

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

//выполняет сортировку выбором строк
//матрицы m по неубыванию значения функции criteria применяемой для строк
void selectionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

//выполняет сортировку выбором столбцов
//матрицы m по неубыванию значения функции criteria применяемой для строк
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

//– возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m);

// – возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool twoMatricesEqual(matrix m1, matrix m2);

// – возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае.
bool isEMatrix(matrix m);

//– возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(matrix m);

// заполняет массив array pos-ой колонной матрицы m;
void getRowFromColumn(matrix m, size_t pos, int *array);

//– транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//возвращает значение элемента матрицы m находящегося на позиции pos
int getElementByPosition(matrix m, position pos);

// – возвращает позицию минимального элемента матрицы m.
position getMinValuePos(matrix m);

//– возвращает позицию максимального элемента матрицы m.
position getMaxValuePos(matrix m);

//возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти:
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
// в динамической памяти, построенных из элементов массива a:
matrix *createArrayOfMatrixFromArray(const int *values,size_t nMatrices, size_t nRows, size_t nCols);

// возвращает произведение матрицы m1 на m2
matrix mulMatrices(matrix m1, matrix m2);

//выполняет сортировку выбором строк
//матрицы m по неубыванию значения функции criteria применяемой для строк
void selectionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));



#endif //LAB_5B_MATRIX_H
