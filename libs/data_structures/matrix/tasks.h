//
// Created by Donpad on 14.02.2022.
//

#ifndef LAB_5B_TASKS_H
#define LAB_5B_TASKS_H

#include "matrix.h"

// обменивает местами строки с наибольшим и наименьшим элементами матрицы m
void swapRowsWithMinAndMax(matrix m);

// возвращает значение отрицательное значение максимального элемента массива a размера n
int getMaxNegative(int *a, int n);

// сортирует строки матрицы m по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

// возвращает отрицательное значение значение минимального элемента массива a размера n
int getMinNegative(int *a, int n);

// сортирует cтолбцы матрицы m по неубыванию наименьших элементов столбцов
void sortColsByMinElement(matrix m);

// если матрица m симметричная, то заменяет её квадратом
void getSquareOfMatrixIfSymmetric(matrix *m);

// транспонирует матрицу m если среди полных сумм строк нет равных
void transposeIfMatrixHasEqualSumOfRows(matrix m);

// возвращает значение "истина", если матрицы m1 и m2 являются взаимнообратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// заполняет массив array размера size элементами диагонали начинающейся с pos - того элемента последней строки матрицы m;
void getArrayFromDiagonal(matrix m, position pos, int *array, size_t *size);

// возвращает сумму максимумов всех псевдодиагонали матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

#endif //LAB_5B_TASKS_H
