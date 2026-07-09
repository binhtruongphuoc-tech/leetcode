#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Hàm kiểm tra 2 chuỗi có khác biệt đúng 1 ký tự hay không
bool isAdj(char* a, char* b) {
    int diff = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            diff++;
            // Nếu khác nhau từ 2 ký tự trở lên, ngắt sớm để tối ưu tốc độ
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize) {
    // 1. Kiểm tra xem endWord có trong từ điển không
    int end_idx = -1;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            end_idx = i;
            break;
        }
    }
    // Nếu không có, chắc chắn không thể biến đổi được
    if (end_idx == -1) return 0;

    // 2. Cấp phát hàng đợi và mảng đánh dấu
    int* visited = (int*)calloc(wordListSize, sizeof(int));
    int* queue = (int*)malloc(wordListSize * sizeof(int));
    int head = 0, tail = 0;

    // 3. Khởi tạo mức đầu tiên (Các từ cách beginWord 1 khoảng)
    for (int i = 0; i < wordListSize; i++) {
        if (isAdj(beginWord, wordList[i])) {
            // Nếu ngay bước đầu đã chạm đích
            if (i == end_idx) {
                free(visited); free(queue);
                return 2; 
            }
            queue[tail++] = i;
            visited[i] = 1;
        }
    }

    // level bắt đầu từ 2 (vì chuỗi tính cả beginWord là 1, và lứa đầu tiên trong queue là 2)
    int level = 2; 
    
    // 4. Bắt đầu duyệt BFS
    while (head < tail) {
        int size = tail - head; // Số lượng từ ở mức hiện tại
        level++; // Chuẩn bị bước sang mức tiếp theo
        
        for (int k = 0; k < size; k++) {
            int u = queue[head++];
            
            // Tìm tất cả các từ có thể biến đổi từ wordList[u]
            for (int v = 0; v < wordListSize; v++) {
                if (!visited[v] && isAdj(wordList[u], wordList[v])) {
                    // Nếu chạm tới đích, trả về kết quả ngay
                    if (v == end_idx) {
                        free(visited); free(queue);
                        return level;
                    }
                    visited[v] = 1; // Đánh dấu đã duyệt
                    queue[tail++] = v;
                }
            }
        }
    }

    // Nếu hàng đợi rỗng mà vẫn chưa tới đích
    free(visited);
    free(queue);
    return 0;
}