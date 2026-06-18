
void backtrack(int* nums, int numsSize, int start, int* path, int pathLen, 
               int** result, int* returnSize, int** returnColumnSizes) {
    
    result[*returnSize] = (int*)malloc(pathLen * sizeof(int));
    for (int i = 0; i < pathLen; i++) {
        result[*returnSize][i] = path[i];
    }
    
    (*returnColumnSizes)[*returnSize] = pathLen;
    
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        path[pathLen] = nums[i];
        
        backtrack(nums, numsSize, i + 1, path, pathLen + 1, result, returnSize, returnColumnSizes);

    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    
    int** result = (int**)malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));
    
    backtrack(nums, numsSize, 0, path, 0, result, returnSize, returnColumnSizes);
    
    free(path);
    
    return result;
}