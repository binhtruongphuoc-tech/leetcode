#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hàm kiểm tra 2 từ có khác nhau đúng 1 ký tự hay không
bool isAdj(char* a, char* b) {
    int diff = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

// Cấu trúc gom nhóm các tham số cho hàm đệ quy để code gọn gàng hơn
typedef struct {
    char** words;
    int (*parents)[505];
    int* parentSize;
    char*** results;
    int* returnColumnSizes;
    int returnSize;
} Context;

// Hàm đệ quy truy vết đường đi từ endWord về beginWord
void backtrack(int u, int* path, int pathLen, Context* ctx) {
    path[pathLen++] = u; // Thêm node hiện tại vào đường đi
    
    // Nếu chạm tới beginWord (chỉ số 0), ta tìm được 1 chuỗi hoàn chỉnh
    if (u == 0) {
        char** seq = (char**)malloc(pathLen * sizeof(char*));
        for (int i = 0; i < pathLen; i++) {
            // Lưu ngược từ dưới lên để đường đi bắt đầu từ beginWord
            seq[i] = ctx->words[path[pathLen - 1 - i]];
        }
        ctx->results[ctx->returnSize] = seq;
        ctx->returnColumnSizes[ctx->returnSize] = pathLen;
        ctx->returnSize++;
        return;
    }
    
    // Tiếp tục đệ quy lùi về các nút cha
    for (int i = 0; i < ctx->parentSize[u]; i++) {
        backtrack(ctx->parents[u][i], path, pathLen, ctx);
    }
}

char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
    // 1. Ánh xạ từ thành chỉ số để tối ưu tốc độ
    char* words[505];
    int M = 0;
    words[M++] = beginWord; // beginWord luôn ở chỉ số 0
    int end_idx = -1;
    
    for (int i = 0; i < wordListSize; i++) {
        // Bỏ qua nếu beginWord vô tình nằm trong wordList
        if (strcmp(wordList[i], beginWord) == 0) continue;
        words[M] = wordList[i];
        if (strcmp(wordList[i], endWord) == 0) end_idx = M;
        M++;
    }
    
    // Nếu không tìm thấy endWord, trả về rỗng ngay lập tức
    if (end_idx == -1) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Cấp phát bộ nhớ cho Đồ thị và BFS (dùng Heap để tránh Stack Overflow)
    int* adjSize = (int*)calloc(M, sizeof(int));
    int (*adj)[505] = (int (*)[505])malloc(M * 505 * sizeof(int));
    
    // 2. Xây dựng đồ thị kề (O(M^2 * L))
    for(int i = 0; i < M; i++) {
        for(int j = i + 1; j < M; j++) {
            if(isAdj(words[i], words[j])) {
                adj[i][adjSize[i]++] = j;
                adj[j][adjSize[j]++] = i;
            }
        }
    }
    
    int* dist = (int*)malloc(M * sizeof(int));
    for(int i = 0; i < M; i++) dist[i] = 10000; // Khởi tạo khoảng cách giả định vô cực
    dist[0] = 0;
    
    int (*parents)[505] = (int (*)[505])malloc(M * 505 * sizeof(int));
    int* parentSize = (int*)calloc(M, sizeof(int));
    
    int* queue = (int*)malloc(M * sizeof(int));
    int head = 0, tail = 0;
    queue[tail++] = 0;
    
    // 3. Tiến hành BFS để tìm đường đi ngắn nhất và lưu dấu vết cha
    while(head < tail) {
        int u = queue[head++];
        for(int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            
            if(dist[v] > dist[u] + 1) {
                // Nếu tìm thấy một đường ngắn hơn đi đến v
                dist[v] = dist[u] + 1;
                parents[v][0] = u; // Ghi đè cha cũ
                parentSize[v] = 1;
                queue[tail++] = v;
            } else if(dist[v] == dist[u] + 1) {
                // Nếu tìm thấy một nhánh khác CŨNG ngắn bằng nhánh trước đó
                parents[v][parentSize[v]++] = u; // Thêm vào danh sách cha
            }
        }
    }
    
    // Nếu duyệt xong mà không tới được end_idx
    if (dist[end_idx] == 10000) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        free(adjSize); free(adj); free(dist); free(parents); free(parentSize); free(queue);
        return NULL;
    }
    
    // 4. Chuẩn bị Backtracking để lấy tất cả đường đi
    // Constraint của LeetCode: "Sum of all sequences does not exceed 10^5"
    // Vậy khoảng 50000 mảng là mức cấp phát cực kỳ an toàn.
    int maxPaths = 50000; 
    char*** results = (char***)malloc(maxPaths * sizeof(char**));
    *returnColumnSizes = (int*)malloc(maxPaths * sizeof(int));
    
    Context ctx = {words, parents, parentSize, results, *returnColumnSizes, 0};
    int path[505];
    
    // Bắt đầu dò ngược từ end_idx về 0
    backtrack(end_idx, path, 0, &ctx);
    
    *returnSize = ctx.returnSize;
    
    // Dọn dẹp bộ nhớ tạm
    free(adjSize); free(adj); free(dist); free(parents); free(parentSize); free(queue);
    
    return results;
}