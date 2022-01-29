#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include
int main() {
    matrix matrix1 = getMemMatrix(3, 3);
    inputMatrix(matrix1);
    swapRows(matrix1, 1, 1);
    outputMatrix(matrix1);
    return 0;
}
