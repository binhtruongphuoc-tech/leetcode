#include <stdio.h>

// Hàm phụ trợ: Lật ngược một đoạn của mảng từ vị trí left đến right
void reverse(int* nums, int left, int right) {
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    // Chuẩn hóa k để tránh trường hợp k lớn hơn kích thước mảng
    k = k % numsSize;
    
    // Nếu k = 0 sau khi chuẩn hóa, mảng không có sự thay đổi
    if (k == 0) return;
    
    // Bước 1: Đảo ngược toàn bộ mảng
    reverse(nums, 0, numsSize - 1);
    
    // Bước 2: Đảo ngược k phần tử đầu tiên
    reverse(nums, 0, k - 1);
    
    // Bước 3: Đảo ngược (numsSize - k) phần tử còn lại phía sau
    reverse(nums, k, numsSize - 1);
}