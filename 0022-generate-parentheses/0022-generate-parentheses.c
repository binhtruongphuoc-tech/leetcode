void backtrack(char ***result, int *capacity, int *returnSize, char *current, int open, int close, int max, int index) {
    if (open == max && close == max) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = (char **)realloc(*result, (*capacity) * sizeof(char *));
        }
        current[index] = '\0';
        (*result)[*returnSize] = (char *)malloc((2 * max + 1) * sizeof(char));
        strcpy((*result)[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < max) {
        current[index] = '(';
        backtrack(result, capacity, returnSize, current, open + 1, close, max, index + 1);
    }
    if (close < open) {
        current[index] = ')';
        backtrack(result, capacity, returnSize, current, open, close + 1, max, index + 1);
    }
}

char ** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int capacity = 1000;
    char **result = (char **)malloc(capacity * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));

    backtrack(&result, &capacity, returnSize, current, 0, 0, n, 0);

    free(current);
    return result;
}