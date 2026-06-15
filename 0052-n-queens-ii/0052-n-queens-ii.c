int solve(int row, int n, unsigned int cols, unsigned int diag1, unsigned int diag2) {
    if (row == n) {
        return 1;
    }
    
    int count = 0;
    unsigned int availablePositions = ((1U << n) - 1) & ~(cols | diag1 | diag2);
    
    while (availablePositions) {
        // Isolate the lowest set bit (the chosen position for the queen)
        unsigned int position = availablePositions & (-availablePositions);
        
        // Clear the lowest set bit
        availablePositions &= availablePositions - 1;
        
        // Recurse to the next row, updating the bitmasks for columns and diagonals
        count += solve(row + 1, n, cols | position, (diag1 | position) << 1, (diag2 | position) >> 1);
    }
    
    return count;
}

int totalNQueens(int n) {
    return solve(0, n, 0, 0, 0);
}