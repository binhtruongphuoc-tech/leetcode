
// Macro tìm giá trị nhỏ nhất
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // Trường hợp mảng rỗng
    if (triangleSize == 0) return 0;

    // Cấp phát mảng 1 chiều để lưu trạng thái DP.
    // Kích thước bằng độ dài của hàng cuối cùng (bằng chính triangleSize)
    int* dp = (int*)malloc(triangleSize * sizeof(int));

    // Khởi tạo mảng DP bằng các giá trị của hàng dưới cùng nhất
    for (int i = 0; i < triangleSize; i++) {
        dp[i] = triangle[triangleSize - 1][i];
    }

    // Bắt đầu duyệt từ hàng ÁP CHÓT đi ngược lên đỉnh
    for (int i = triangleSize - 2; i >= 0; i--) {
        // Duyệt qua các phần tử của hàng hiện tại
        for (int j = 0; j <= i; j++) {
            // Cập nhật lại dp[j] bằng:
            // Giá trị của node hiện tại + Min của hai node con ở hàng dưới
            dp[j] = triangle[i][j] + MIN(dp[j], dp[j + 1]);
        }
    }

    // Khi vòng lặp kết thúc, dp[0] sẽ chứa tổng đường đi nhỏ nhất từ đỉnh
    int result = dp[0];
    
    // Dọn dẹp bộ nhớ
    free(dp);
    
    return result;
}