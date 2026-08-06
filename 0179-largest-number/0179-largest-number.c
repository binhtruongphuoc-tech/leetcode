#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm so sánh tùy chỉnh cho qsort
int compare(const void* a, const void* b) {
    // Ép kiểu con trỏ void thành con trỏ chuỗi
    const char** str_a = (const char**)a;
    const char** str_b = (const char**)b;
    
    // Tạo 2 mảng đệm để chứa kết quả ghép (max mỗi số 10 chữ số, nên 25 là đủ dư)
    char ab[25];
    char ba[25];
    
    // Ghép A+B và B+A
    sprintf(ab, "%s%s", *str_a, *str_b);
    sprintf(ba, "%s%s", *str_b, *str_a);
    
    // Để sắp xếp giảm dần, ta lấy 'ba' so sánh với 'ab'
    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
    // 1. Cấp phát mảng con trỏ để lưu các số dưới dạng chuỗi
    char** str_nums = (char**)malloc(numsSize * sizeof(char*));
    int total_len = 0; // Tính tổng chiều dài để cấp phát bộ nhớ một lần cho kết quả
    
    for (int i = 0; i < numsSize; i++) {
        // Một số nguyên 32-bit (chưa tới 10 tỷ) có tối đa 10 chữ số + '\0' -> cấp phát 12 ký tự
        str_nums[i] = (char*)malloc(12 * sizeof(char));
        sprintf(str_nums[i], "%d", nums[i]);
        total_len += strlen(str_nums[i]);
    }
    
    // 2. Sắp xếp mảng chuỗi với hàm compare tùy chỉnh
    qsort(str_nums, numsSize, sizeof(char*), compare);
    
    // 3. Xử lý ngoại lệ: Mảng toàn số 0
    if (str_nums[0][0] == '0') {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        
        // Dọn dẹp bộ nhớ
        for (int i = 0; i < numsSize; i++) free(str_nums[i]);
        free(str_nums);
        
        return result;
    }
    
    // 4. Ghép các chuỗi đã sắp xếp lại thành kết quả cuối cùng
    char* result = (char*)malloc((total_len + 1) * sizeof(char));
    char* current_ptr = result;
    
    for (int i = 0; i < numsSize; i++) {
        strcpy(current_ptr, str_nums[i]);
        current_ptr += strlen(str_nums[i]); // Dịch con trỏ để nối chuỗi tiếp theo trong O(1)
        free(str_nums[i]); // Giải phóng bộ nhớ chuỗi con ngay khi dùng xong
    }
    
    free(str_nums);
    
    return result;
}