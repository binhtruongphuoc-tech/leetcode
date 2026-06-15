
void backtrack(int n, int row, char **board, int *cols, int *posDiag, int *negDiag, 
               char ****result, int *returnSize, int *capacity) {
    if (row == n) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = (char ***)realloc(*result, (*capacity) * sizeof(char **));
        }
        
        char **newBoard = (char **)malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++) {
            newBoard[i] = (char *)malloc((n + 1) * sizeof(char));
            strcpy(newBoard[i], board[i]);
        }
        
        (*result)[*returnSize] = newBoard;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        int posIdx = row + col;
        int negIdx = row - col + n - 1;
        
        if (cols[col] || posDiag[posIdx] || negDiag[negIdx]) {
            continue;
        }

        board[row][col] = 'Q';
        cols[col] = 1;
        posDiag[posIdx] = 1;
        negDiag[negIdx] = 1;

        backtrack(n, row + 1, board, cols, posDiag, negDiag, result, returnSize, capacity);

        board[row][col] = '.';
        cols[col] = 0;
        posDiag[posIdx] = 0;
        negDiag[negIdx] = 0;
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 500; 
    char ***result = (char ***)malloc(capacity * sizeof(char **));
    
    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }

    int *cols = (int *)calloc(n, sizeof(int));
    int *posDiag = (int *)calloc(2 * n, sizeof(int));
    int *negDiag = (int *)calloc(2 * n, sizeof(int));

    backtrack(n, 0, board, cols, posDiag, negDiag, &result, returnSize, &capacity);

    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    free(cols);
    free(posDiag);
    free(negDiag);

    return result;
}