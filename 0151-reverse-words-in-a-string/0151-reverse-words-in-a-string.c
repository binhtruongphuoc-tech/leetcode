#include <string.h>

// Hàm phụ trợ: Lật ngược một đoạn chuỗi từ vị trí left đến right
void reverseSegment(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s);
    int i = 0; // Con trỏ Ghi (vị trí sẽ ghi ký tự hợp lệ)
    int j = 0; // Con trỏ Đọc (dò tìm ký tự trên chuỗi gốc)

    // BƯỚC 1: Dọn dẹp khoảng trắng
    while (j < n) {
        // Bỏ qua các khoảng trắng liên tiếp
        while (j < n && s[j] == ' ') {
            j++;
        }
        
        // Nếu không phải là từ đầu tiên thì chèn thêm 1 khoảng trắng ngăn cách
        if (j < n && i > 0) {
            s[i++] = ' ';
        }
        
        // Chép từng ký tự của từ hiện tại vào vị trí i
        while (j < n && s[j] != ' ') {
            s[i++] = s[j++];
        }
    }
    s[i] = '\0'; // Đặt điểm kết thúc cho chuỗi mới đã được nén gọn
    int newLen = i; // Chiều dài mới của chuỗi

    // BƯỚC 2: Lật ngược toàn bộ chuỗi
    reverseSegment(s, 0, newLen - 1);

    // BƯỚC 3: Lật ngược từng từ bên trong chuỗi
    int start = 0;
    for (int end = 0; end <= newLen; end++) {
        // Nếu gặp dấu cách hoặc chạm đến cuối chuỗi, ta đã tìm được một từ
        if (s[end] == ' ' || s[end] == '\0') {
            reverseSegment(s, start, end - 1); // Lật ngược từ đó
            start = end + 1;                   // Dời start sang từ tiếp theo
        }
    }

    return s;
}