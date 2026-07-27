#include <stdio.h>

// Macro tìm max và min
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Khởi tạo cả 3 biến với giá trị của phần tử đầu tiên
    int max_prod = nums[0];
    int min_prod = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // Nếu gặp số âm, hoán đổi max_prod và min_prod
        if (nums[i] < 0) {
            int temp = max_prod;
            max_prod = min_prod;
            min_prod = temp;
        }

        // Tích lớn nhất/nhỏ nhất kết thúc tại i có thể là:
        // 1. Nhân tiếp với chuỗi phía trước (max_prod * nums[i])
        // 2. Tự đứng một mình bắt đầu mảng con mới (nums[i])
        max_prod = MAX(nums[i], max_prod * nums[i]);
        min_prod = MIN(nums[i], min_prod * nums[i]);

        // Cập nhật kết quả lớn nhất tìm được toàn cục
        result = MAX(result, max_prod);
    }

    return result;
}