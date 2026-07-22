/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Hàm phụ trợ 1: Đếm tổng số node trong cây để cấp phát mảng
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Hàm phụ trợ 2: Duyệt cây theo Preorder (Gốc -> Trái -> Phải)
void dfsPreorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    
    // 1. Xử lý Gốc (Root)
    result[*index] = root->val;
    (*index)++;
    
    // 2. Duyệt nhánh Trái (Left)
    dfsPreorder(root->left, result, index);
    
    // 3. Duyệt nhánh Phải (Right)
    dfsPreorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Xác định kích thước mảng cần thiết
    *returnSize = countNodes(root);
    
    // Nếu cây rỗng, trả về NULL
    if (*returnSize == 0) {
        return NULL;
    }
    
    // Cấp phát mảng kết quả
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    // Bắt đầu điền giá trị từ vị trí 0
    int index = 0;
    dfsPreorder(root, result, &index);
    
    return result;
}