#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix matrix1 = getMemMatrix(3, 3);
    inputMatrix(matrix1);
    outputMatrix(matrix1);

    return 0;
}
