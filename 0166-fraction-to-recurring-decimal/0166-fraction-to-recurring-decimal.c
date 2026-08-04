#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 10007

// Cấu trúc cho một phần tử trong Bảng băm
typedef struct {
    long long key; // Lưu số dư
    int val;       // Lưu vị trí (index) của số dư này trong chuỗi kết quả
    bool used;     // Đánh dấu xem slot này đã có dữ liệu chưa
} HashItem;

// Hàm tìm kiếm trong Bảng băm (Linear Probing)
int find(HashItem* hash, long long key) {
    int idx = key % HASH_SIZE;
    while (hash[idx].used) {
        if (hash[idx].key == key) return hash[idx].val;
        idx = (idx + 1) % HASH_SIZE;
    }
    return -1; // Không tìm thấy
}

// Hàm thêm vào Bảng băm
void insert(HashItem* hash, long long key, int val) {
    int idx = key % HASH_SIZE;
    while (hash[idx].used) {
        if (hash[idx].key == key) {
            hash[idx].val = val;
            return;
        }
        idx = (idx + 1) % HASH_SIZE;
    }
    hash[idx].key = key;
    hash[idx].val = val;
    hash[idx].used = true;
}

char* fractionToDecimal(int numerator, int denominator) {
    // Xử lý trường hợp tử số bằng 0 để tránh in ra "-0"
    if (numerator == 0) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    // Cấp phát mảng lớn (giới hạn đề bài là < 10^4)
    char* res = (char*)malloc(10050 * sizeof(char));
    int pos = 0;

    // 1. Xác định dấu âm/dương bằng phép XOR (^)
    if ((numerator < 0) ^ (denominator < 0)) {
        res[pos++] = '-';
    }

    // Ép sang long long và lấy trị tuyệt đối để chống tràn số
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    // 2. Tính phần nguyên
    long long integral = num / den;
    long long rem = num % den;
    
    // Ghi phần nguyên vào chuỗi và cập nhật vị trí con trỏ pos
    pos += sprintf(res + pos, "%lld", integral);

    // Nếu không có phần thập phân, kết thúc
    if (rem == 0) {
        res[pos] = '\0';
        return res;
    }

    // 3. Tính phần thập phân
    res[pos++] = '.';

    // Khởi tạo Bảng băm
    HashItem hash[HASH_SIZE];
    memset(hash, 0, sizeof(hash));

    while (rem != 0) {
        int prevPos = find(hash, rem);
        
        // Nếu số dư đã tồn tại -> Tìm thấy chu kỳ lặp
        if (prevPos != -1) {
            // Dịch chuyển toàn bộ chu kỳ lặp sang phải 1 bước để nhường chỗ cho dấu '('
            memmove(res + prevPos + 1, res + prevPos, pos - prevPos);
            res[prevPos] = '(';
            res[pos + 1] = ')';
            res[pos + 2] = '\0';
            return res;
        }

        // Lưu số dư và vị trí hiện tại vào Bảng băm
        insert(hash, rem, pos);

        // Mô phỏng đặt tính chia
        rem *= 10;
        res[pos++] = (rem / den) + '0';
        rem %= den;
    }

    // Kết thúc chuỗi nếu phép chia hết (thập phân hữu hạn)
    res[pos] = '\0';
    return res;
}