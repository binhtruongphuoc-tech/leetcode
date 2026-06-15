bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    short rows[9] = {0};
    short cols[9] = {0};
    short boxes[9] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            int val = board[i][j] - '0';
            int bit = 1 << val;
            int box_index = (i / 3) * 3 + (j / 3);
            if ((rows[i] & bit) || (cols[j] & bit) || (boxes[box_index] & bit)) {
                return false; 
            }
            rows[i] |= bit;
            cols[j] |= bit;
            boxes[box_index] |= bit;
        }
    }
    return true;
}