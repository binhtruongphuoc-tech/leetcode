#include <stddef.h>

// Hàm DFS để loang và đánh dấu các ô 'O' liên thông với viền thành '#'
void dfs(char** board, int r, int c, int rows, int cols) {
    // Điều kiện dừng: Vượt quá ranh giới hoặc ô hiện tại không phải là 'O'
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
        return;
    }
    
    // Đánh dấu ô này là an toàn
    board[r][c] = '#';
    
    // Tiếp tục loang ra 4 hướng
    dfs(board, r - 1, c, rows, cols); // Lên
    dfs(board, r + 1, c, rows, cols); // Xuống
    dfs(board, r, c - 1, rows, cols); // Trái
    dfs(board, r, c + 1, rows, cols); // Phải
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || boardColSize == NULL) {
        return;
    }
    
    int rows = boardSize;
    int cols = boardColSize[0];
    
    // 1. Quét hàng đầu tiên và hàng cuối cùng
    for (int c = 0; c < cols; c++) {
        if (board[0][c] == 'O') dfs(board, 0, c, rows, cols);
        if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c, rows, cols);
    }
    
    // 2. Quét cột đầu tiên và cột cuối cùng
    for (int r = 0; r < rows; r++) {
        if (board[r][0] == 'O') dfs(board, r, 0, rows, cols);
        if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1, rows, cols);
    }
    
    // 3. Duyệt lại toàn bộ ma trận để lật kết quả
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 'O') {
                // Những ô 'O' không nối với viền sẽ bị bắt thành 'X'
                board[r][c] = 'X';
            } else if (board[r][c] == '#') {
                // Trả lại 'O' cho những ô an toàn
                board[r][c] = 'O';
            }
        }
    }
}