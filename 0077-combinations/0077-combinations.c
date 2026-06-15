void backtrack(int n, int k, int start, int* path, int path_len, int** result, int* returnSize, int** returnColumnSizes) {
    if (path_len == k) {
        result[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n - (k - path_len) + 1; i++) {
        path[path_len] = i;
        backtrack(n, k, i + 1, path, path_len + 1, result, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    long long total_combinations = 1;
    for (int i = 1; i <= k; i++) {
        total_combinations = total_combinations * (n - i + 1) / i;
    }

    int** result = (int**)malloc(total_combinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total_combinations * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(k * sizeof(int));

    backtrack(n, k, 1, path, 0, result, returnSize, returnColumnSizes);

    free(path);

    return result;
}