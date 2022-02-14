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

#endif //LAB_5B_TASKS_H
