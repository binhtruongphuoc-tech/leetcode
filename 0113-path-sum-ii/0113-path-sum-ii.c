/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Hàm đệ quy DFS kết hợp Backtracking
void dfs(struct TreeNode* root, int targetSum, int* currentPath, int pathLen,
         int** result, int* returnSize, int** returnColumnSizes) {
    // Điều kiện dừng: Nếu node rỗng
    if (root == NULL) return;

    // Thêm giá trị của node hiện tại vào đường đi
    currentPath[pathLen] = root->val;
    pathLen++; // Tăng độ dài đường đi
    targetSum -= root->val; // Trừ đi giá trị node hiện tại

    // Nếu là node lá và tổng các node bằng targetSum
    if (root->left == NULL && root->right == NULL && targetSum == 0) {
        // Cấp phát bộ nhớ cho một đường đi mới trong mảng kết quả
        result[*returnSize] = (int*)malloc(pathLen * sizeof(int));
        for (int i = 0; i < pathLen; i++) {
            result[*returnSize][i] = currentPath[i];
        }
        // Lưu lại độ dài của đường đi này
        (*returnColumnSizes)[*returnSize] = pathLen;
        // Tăng số lượng đường đi tìm được
        (*returnSize)++;
    } else {
        // Nếu chưa phải lá hoặc chưa đủ tổng, tiếp tục duyệt DFS xuống 2 con
        dfs(root->left, targetSum, currentPath, pathLen, result, returnSize, returnColumnSizes);
        dfs(root->right, targetSum, currentPath, pathLen, result, returnSize, returnColumnSizes);
    }
    
    // Việc quay lui (Backtracking) diễn ra tự nhiên ở đây: 
    // Vì pathLen được truyền theo giá trị (pass by value), 
    // nên khi hàm trả về, pathLen ở call stack trước đó không bị thay đổi.
}


int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int maxPaths = 2000;
    int** result = (int**)malloc(maxPaths * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxPaths * sizeof(int));

 
    int* currentPath = (int*)malloc(5000 * sizeof(int));

    dfs(root, targetSum, currentPath, 0, result, returnSize, returnColumnSizes);

    free(currentPath);

    return result;
}