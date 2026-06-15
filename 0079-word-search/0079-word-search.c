
bool dfs(char** board, int boardSize, int* boardColSize, int i, int j, char* word, int index) {
    // Nếu index bằng chiều dài chuỗi, ta đã quét xong toàn bộ từ thành công
    if (word[index] == '\0') {
        return true;
    }
    
    // Kiểm tra ranh giới lưới (Out of bounds)
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i]) {
        return false;
    }
    
    // Nếu chữ trên bảng không khớp với chữ đang tìm, hoặc ô này đang bị đánh dấu '*'
    if (board[i][j] != word[index]) {
        return false;
    }
    
    // LƯU TRẠNG THÁI (Đánh dấu đã thăm)
    char temp = board[i][j];
    board[i][j] = '*'; 
    
    // GỌI ĐỆ QUY (Thử 4 hướng: Lên, Dưới, Trái, Phải)
    bool found = dfs(board, boardSize, boardColSize, i - 1, j, word, index + 1) || // Lên
                 dfs(board, boardSize, boardColSize, i + 1, j, word, index + 1) || // Dưới
                 dfs(board, boardSize, boardColSize, i, j - 1, word, index + 1) || // Trái
                 dfs(board, boardSize, boardColSize, i, j + 1, word, index + 1);   // Phải
                 
    // QUAY LUI (Backtrack: Xóa dấu vết để nhường đường cho nhánh đệ quy khác nếu cần)
    board[i][j] = temp;
    
    return found;
}

// Hàm chính
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    // Quét toàn bộ lưới để tìm điểm xuất phát phù hợp
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            // Nếu chữ cái đầu tiên khớp, bắt đầu dò đường (DFS) từ tọa độ (i, j)
            if (board[i][j] == word[0]) {
                if (dfs(board, boardSize, boardColSize, i, j, word, 0)) {
                    return true;
                }
            }
        }
    }
    
    return false; // Quét sạch lưới mà không tìm thấy
}