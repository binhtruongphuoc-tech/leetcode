#include <string.h>

int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    int len1 = strlen(version1);
    int len2 = strlen(version2);

    // Duyệt đến khi cả hai chuỗi đều đã được xét hết
    while (i < len1 || j < len2) {
        long num1 = 0;
        long num2 = 0;

        // Đọc giá trị phân đoạn của version1
        while (i < len1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        // Bỏ qua dấu chấm nếu có
        if (i < len1 && version1[i] == '.') {
            i++;
        }

        // Đọc giá trị phân đoạn của version2
        while (j < len2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }
        // Bỏ qua dấu chấm nếu có
        if (j < len2 && version2[j] == '.') {
            j++;
        }

        // So sánh hai phân đoạn vừa trích xuất
        if (num1 < num2) {
            return -1;
        }
        if (num1 > num2) {
            return 1;
        }
    }

    // Hai phiên bản hoàn toàn tương đương
    return 0;
}