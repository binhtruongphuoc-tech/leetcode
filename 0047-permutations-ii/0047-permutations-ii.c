
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Hàm quay lui (Backtracking)
void backtrack(int* nums, int numsSize, bool* used, int* path, int pathIndex, int** result, int* returnSize, int** returnColumnSizes) {
    // Điều kiện dừng: Khi đã xếp đủ số lượng phần tử
    if (pathIndex == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    // Duyệt qua tất cả các phần tử để tìm ứng viên cho vị trí pathIndex
    for (int i = 0; i < numsSize; i++) {
        // Nếu phần tử này đã được đưa vào đường đi hiện tại thì bỏ qua
        if (used[i]) {
            continue;
        }

   
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            continue;
        }
        used[i] = true;
        path[pathIndex] = nums[i];
                backtrack(nums, numsSize, used, path, pathIndex + 1, result, returnSize, returnColumnSizes);
                used[i] = false;
    }
}



int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int max_permutations = 40320; 
    int** result = (int**)malloc(max_permutations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_permutations * sizeof(int));
    *returnSize = 0;
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    int* path = (int*)malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, used, path, 0, result, returnSize, returnColumnSizes);
    free(used);
    free(path);
    
    return result;
}