//
// Created by Donpad on 14.02.2022.
//

#include "tasks.h"
#include "matrix.h"

/// task 1
void swapRowsWithMinAndMax(matrix m){
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

/// task 2;
void sortRowsByMinElement(matrix m){
    insertionSortRowsMatrixByRowCriteria(m, )

}



