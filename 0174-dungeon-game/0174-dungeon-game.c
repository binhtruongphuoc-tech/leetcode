#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int m = dungeonSize;
    int n = dungeonColSize[0];
    
    // Cấp phát mảng DP 1 chiều lưu trữ lượng máu cần thiết của một hàng
    int* dp = (int*)malloc(n * sizeof(int));
    
    // 1. Xử lý hàng cuối cùng chứa Công chúa (từ phải sang trái)
    // Ô của công chúa
    dp[n-1] = MAX(1, 1 - dungeon[m-1][n-1]);
    
    // Các ô còn lại của hàng cuối (chỉ có thể đi sang phải)
    for (int j = n - 2; j >= 0; j--) {
        dp[j] = MAX(1, dp[j+1] - dungeon[m-1][j]);
    }
    
    // 2. Xử lý các hàng phía trên (từ dưới lên trên, từ phải sang trái)
    for (int i = m - 2; i >= 0; i--) {
        // Cập nhật ô ngoài cùng bên phải của hàng i (chỉ có thể đi xuống)
        dp[n-1] = MAX(1, dp[n-1] - dungeon[i][n-1]);
        
        // Cập nhật các ô còn lại
        for (int j = n - 2; j >= 0; j--) {
            // dp[j] lúc này đóng vai trò là ô bên dưới (chưa bị ghi đè)
            // dp[j+1] là ô bên phải (vừa được tính ở vòng lặp trước)
            int min_hp_next = MIN(dp[j], dp[j+1]);
            
            // Tính lượng máu tối thiểu cho ô hiện tại
            dp[j] = MAX(1, min_hp_next - dungeon[i][j]);
        }
    }
    
    int result = dp[0];
    free(dp);
    
    return result; // dp[0] chính là lượng máu cần thiết tại vạch xuất phát (0, 0)
}