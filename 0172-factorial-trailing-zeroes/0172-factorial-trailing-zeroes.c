#include <stdio.h>

int trailingZeroes(int n) {
    int count = 0;
        while (n > 0) {
        n = n / 5;       // Cập nhật n bằng n chia 5 (tương đương mẫu số tăng từ 5 -> 25 -> 125...)
        count += n;      // Cộng dồn vào tổng số lượng chữ số 0
    }
    
    return count;
}