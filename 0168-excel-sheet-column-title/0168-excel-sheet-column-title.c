#include <stdlib.h>
#include <string.h>

// Hàm phụ trợ để lật ngược chuỗi
void reverseString(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* convertToTitle(int columnNumber) {
    // Cấp phát mảng tĩnh 10 ký tự (7 ký tự dữ liệu + 1 ký tự null kết thúc)
    char* result = (char*)malloc(10 * sizeof(char));
    int index = 0;

    while (columnNumber > 0) {
        // Lùi 1 đơn vị để đồng bộ với hệ 0-based
        columnNumber--; 
        
        // Trích xuất ký tự hiện tại và lưu vào mảng
        int remainder = columnNumber % 26;
        result[index++] = remainder + 'A';
        
        // Chuyển sang hàng tiếp theo
        columnNumber /= 26;
    }
    
    // Đóng chuỗi
    result[index] = '\0';
    
    // Chuỗi đang bị ngược từ phải sang trái, cần lật lại
    reverseString(result);
    
    return result;
}