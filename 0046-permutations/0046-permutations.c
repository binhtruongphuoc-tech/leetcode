
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtrack(int* nums, int numsSize, int start, int** result, int* returnSize, int* returnColumnSizes) {
    if (start == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = nums[i];
        }
        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, result, returnSize, returnColumnSizes);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int fact = 1;
    for (int i = 1; i <= numsSize; i++) {
        fact *= i;
    }

    int** result = (int**)malloc(fact * sizeof(int*));
    *returnColumnSizes = (int*)malloc(fact * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, result, returnSize, *returnColumnSizes);

    return result;
}