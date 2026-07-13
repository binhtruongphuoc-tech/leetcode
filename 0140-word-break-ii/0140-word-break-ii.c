#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hàm phụ trợ để thêm một câu hoàn chỉnh vào danh sách kết quả
void addResult(char*** results, int* returnSize, int* capacity, char* sentence) {
    if (*returnSize >= *capacity) {
        *capacity *= 2;
        *results = (char**)realloc(*results, *capacity * sizeof(char*));
    }
    // strdup giúp nhân bản chuỗi để lưu trữ an toàn (hàm chuẩn trong POSIX)
    (*results)[*returnSize] = strdup(sentence);
    (*returnSize)++;
}

// Hàm đệ quy Quay lui
void backtrack(char* s, int start, int sLen, char** wordDict, int wordDictSize,
               char* path, int pathLen, char*** results, int* returnSize, int* capacity) {
    
    // Điều kiện dừng: Đã duyệt hết chuỗi s
    if (start == sLen) {
        // Loại bỏ dấu cách ' ' thừa ở cuối câu (nếu có) và đóng chuỗi
        if (pathLen > 0 && path[pathLen - 1] == ' ') {
            path[pathLen - 1] = '\0';
        } else {
            path[pathLen] = '\0';
        }
        
        // Thêm câu hợp lệ vào kết quả
        addResult(results, returnSize, capacity, path);
        
        // Trả lại dấu cách để các nhánh đệ quy khác tiếp tục chạy đúng
        if (pathLen > 0) {
            path[pathLen - 1] = ' ';
        }
        return;
    }

    // Thử ghép với từng từ trong từ điển
    for (int i = 0; i < wordDictSize; i++) {
        int wLen = strlen(wordDict[i]);
        
        // Kiểm tra xem từ hiện tại có khớp với phần đầu của s (từ vị trí start) không
        if (start + wLen <= sLen && strncmp(&s[start], wordDict[i], wLen) == 0) {
            
            // Nối từ vào đường đi hiện tại (path)
            strcpy(&path[pathLen], wordDict[i]);
            int nextPathLen = pathLen + wLen;
            
            // Thêm dấu cách sau từ vừa nối
            path[nextPathLen] = ' ';
            
            // Đệ quy để xử lý phần còn lại của chuỗi s
            backtrack(s, start + wLen, sLen, wordDict, wordDictSize, 
                      path, nextPathLen + 1, results, returnSize, capacity);
        }
    }
}

char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize) {
    int capacity = 100;
    char** results = (char**)malloc(capacity * sizeof(char*));
    *returnSize = 0;
    
    int sLen = strlen(s);
    
    // Với chiều dài tối đa của s là 20, mỗi ký tự đi kèm 1 khoảng trắng, 
    // mảng path có kích thước 50 là cực kỳ an toàn
    char path[50]; 
    
    backtrack(s, 0, sLen, wordDict, wordDictSize, path, 0, &results, returnSize, &capacity);
    
    return results;
}