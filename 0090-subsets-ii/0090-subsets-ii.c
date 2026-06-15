#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* path, int pathLen, int** result, int* returnSize, int** returnColumnSizes) {
    result[*returnSize] = (int*)malloc(pathLen * sizeof(int));
    for (int i = 0; i < pathLen; i++) {
        result[*returnSize][i] = path[i];
    }
    (*returnColumnSizes)[*returnSize] = pathLen;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        path[pathLen] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathLen + 1, result, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int max_subsets = 1 << numsSize;
    int** result = (int**)malloc(max_subsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_subsets * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, path, 0, result, returnSize, returnColumnSizes);

    free(path);
    return result;
}