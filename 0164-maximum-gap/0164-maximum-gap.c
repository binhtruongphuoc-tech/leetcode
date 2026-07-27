#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;
    
    // 1. Tìm giá trị nhỏ nhất và lớn nhất trong mảng
    int min_val = nums[0];
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min_val = MIN(min_val, nums[i]);
        max_val = MAX(max_val, nums[i]);
    }
    
    // Nếu tất cả các số giống hệt nhau, khoảng cách bằng 0
    if (min_val == max_val) return 0;
    
    // 2. Tính kích thước thùng (gap) và số lượng thùng
    // Dùng hàm ceil (làm tròn lên) để đảm bảo không bị thiếu kích thước
    int gap = (int)ceil((double)(max_val - min_val) / (numsSize - 1));
    int bucket_count = (max_val - min_val) / gap + 1;
    
    // 3. Khởi tạo các thùng (Lưu min, max và trạng thái sử dụng)
    int* bucket_min = (int*)malloc(bucket_count * sizeof(int));
    int* bucket_max = (int*)malloc(bucket_count * sizeof(int));
    bool* bucket_used = (bool*)calloc(bucket_count, sizeof(bool)); // Tự động điền false (0)
    
    // Phân bổ các phần tử vào thùng
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - min_val) / gap;
        
        if (!bucket_used[idx]) {
            bucket_min[idx] = nums[i];
            bucket_max[idx] = nums[i];
            bucket_used[idx] = true;
        } else {
            bucket_min[idx] = MIN(bucket_min[idx], nums[i]);
            bucket_max[idx] = MAX(bucket_max[idx], nums[i]);
        }
    }
    
    // 4. Tìm khoảng cách lớn nhất
    int max_gap = 0;
    int prev_max = min_val; // Lưu giá trị max của thùng có chứa dữ liệu trước đó
    
    for (int i = 0; i < bucket_count; i++) {
        // Bỏ qua các thùng rỗng
        if (!bucket_used[i]) continue;
        
        // Khoảng cách = min của thùng hiện tại trừ đi max của thùng liền trước
        max_gap = MAX(max_gap, bucket_min[i] - prev_max);
        
        // Cập nhật lại prev_max cho vòng lặp sau
        prev_max = bucket_max[i];
    }
    
    // Dọn dẹp bộ nhớ
    free(bucket_min);
    free(bucket_max);
    free(bucket_used);
    
    return max_gap;
}