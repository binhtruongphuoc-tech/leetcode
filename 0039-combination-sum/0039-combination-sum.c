int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target, int index, 
               int* current, int currentSize, int currentSum, 
               int*** result, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (currentSum == target) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        
        (*result)[*returnSize] = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            (*result)[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }

    for (int i = index; i < candidatesSize; i++) {
        if (currentSum + candidates[i] > target) {
            break;
        }
        
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target, i, current, currentSize + 1, 
                  currentSum + candidates[i], result, returnSize, returnColumnSizes, capacity);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int capacity = 150;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;
    
    int* current = (int*)malloc(100 * sizeof(int));
    
    backtrack(candidates, candidatesSize, target, 0, current, 0, 0, 
              &result, returnSize, returnColumnSizes, &capacity);
    
    free(current);
    return result;
}