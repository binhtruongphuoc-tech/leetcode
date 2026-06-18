#include <stdlib.h>
#include <string.h>

// Bảng ánh xạ từ chữ số (0-9) sang các chữ cái tương ứng trên bàn phím điện thoại
const char* phoneMap[] = {
    "",     // 0 không có
    "",     // 1 không có
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

// Hàm đệ quy quay lui (Backtracking)
void backtrack(char* digits, int index, char* currentPath, char** result, int* returnSize) {
    // Base case: Nếu độ dài chuỗi tạm bằng với số lượng chữ số ban đầu -> Đã tạo xong 1 tổ hợp
    if (index == strlen(digits)) {
        // Cấp phát bộ nhớ cho chuỗi kết quả và copy chuỗi tạm vào mảng result
        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], currentPath);
        (*returnSize)++;
        return;
    }

    // Chuyển ký tự số hiện tại thành số nguyên (ví dụ: '2' -> 2)
    int digit = digits[index] - '0';
    const char* letters = phoneMap[digit];

    // Duyệt qua từng chữ cái tương ứng với chữ số đó
    for (int i = 0; i < strlen(letters); i++) {
        currentPath[index] = letters[i]; // Thử ghép chữ cái này vào vị trí hiện tại
        
        // Gọi đệ quy để xử lý chữ số tiếp theo
        backtrack(digits, index + 1, currentPath, result, returnSize);
        
        // Trong C, ta ghi đè trực tiếp lên currentPath ở vòng lặp tiếp theo
        // nên không cần phải có bước "pop" (xóa) ký tự như trong C++ hoặc Python.
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    *returnSize = 0;
    if (len == 0) {
        return NULL;
    }
    int totalCombinations = 1;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        totalCombinations *= strlen(phoneMap[digit]);
    }

    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    char* currentPath = (char*)malloc((len + 1) * sizeof(char));
    currentPath[len] = '\0'; 
    backtrack(digits, 0, currentPath, result, returnSize);
    free(currentPath);

    return result;
}