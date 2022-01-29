#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix matrix1 = getMemMatrix(3, 3);
    inputMatrix(matrix1);
    swapColumns(matrix1, 0, 2);
    outputMatrix(matrix1);
    return 0;
}
