

// Hàm kiểm tra một phần (segment) của IP có hợp lệ không
int isValidSegment(char* s, int start, int len) {
    // Không được có số 0 ở đầu nếu độ dài lớn hơn 1
    if (len > 1 && s[start] == '0') return 0;
    
    // Tính giá trị số nguyên
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + (s[start + i] - '0');
    }
    
    // Phải nằm trong khoảng 0 - 255
    if (num > 255) return 0;
    
    return 1;
}

// Hàm đệ quy quay lui
void backtrack(char* s, int len_s, int s_idx, int step, char* path, int path_idx, char** result, int* returnSize) {
    // Điều kiện dừng: Nếu đã đủ 4 phần
    if (step == 4) {
        // Nếu đã dùng hết chuỗi -> Hợp lệ
        if (s_idx == len_s) {
            path[path_idx] = '\0'; // Kết thúc chuỗi
            result[*returnSize] = (char*)malloc((path_idx + 1) * sizeof(char));
            strcpy(result[*returnSize], path);
            (*returnSize)++;
        }
        return; // Hết chuỗi hay chưa cũng phải quay lui
    }
    
    // Thử cắt các đoạn có độ dài 1, 2, 3
    for (int len = 1; len <= 3; len++) {
        // Tránh vượt quá độ dài chuỗi gốc
        if (s_idx + len > len_s) break;
        
        // Kiểm tra tính hợp lệ của đoạn cắt
        if (isValidSegment(s, s_idx, len)) {
            // Lưu lại vị trí path_idx hiện tại để quay lui
            int current_path_idx = path_idx;
            
            // Ghi đoạn vừa cắt vào path
            for (int i = 0; i < len; i++) {
                path[path_idx++] = s[s_idx + i];
            }
            
            // Thêm dấu chấm nếu chưa phải là phần cuối cùng (step 3)
            if (step < 3) {
                path[path_idx++] = '.';
            }
            
            // Đệ quy đi tiếp
            backtrack(s, len_s, s_idx + len, step + 1, path, path_idx, result, returnSize);
            
            // Quay lui (Backtrack): Phục hồi lại path_idx như cũ để thử độ dài len khác
            path_idx = current_path_idx;
        }
    }
}

/**
 * Lưu ý: Mảng trả về và các chuỗi bên trong phải được malloc.
 * Caller sẽ chịu trách nhiệm gọi free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    int len_s = strlen(s);
    
    // Tối ưu: IP hợp lệ có độ dài từ 4 đến 12 ký tự số
    if (len_s < 4 || len_s > 12) {
        return NULL;
    }
    
    // Cấp phát mảng con trỏ kết quả (tối đa không quá 200 đáp án)
    char** result = (char**)malloc(200 * sizeof(char*));
    
    // Chuỗi tạm thời path dài tối đa 16 ký tự (12 số + 3 chấm + '\0')
    char path[16]; 
    
    // Gọi hàm quay lui
    backtrack(s, len_s, 0, 0, path, 0, result, returnSize);
    
    return result;
}