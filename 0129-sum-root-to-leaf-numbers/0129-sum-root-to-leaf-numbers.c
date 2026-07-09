/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stddef.h>

// Hàm đệ quy DFS phụ trợ
int dfs(struct TreeNode* node, int currentSum) {
    // Điều kiện an toàn: nếu truyền vào một node rỗng
    if (node == NULL) {
        return 0;
    }
    
    // Đẩy các chữ số cũ sang trái 1 hàng (nhân 10) và nối thêm chữ số mới
    currentSum = currentSum * 10 + node->val;
    
    // Nếu gặp node lá, trả về con số nguyên vẹn vừa ghép được
    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }
    
    // Tiếp tục tính tổng các số hình thành từ nhánh trái và nhánh phải
    return dfs(node->left, currentSum) + dfs(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    // Bắt đầu từ node gốc, giá trị khởi tạo lúc chưa ghép chữ số nào là 0
    return dfs(root, 0);
}