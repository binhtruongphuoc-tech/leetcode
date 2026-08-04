/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc Iterator chứa Stack
typedef struct {
    struct TreeNode** stack;
    int top;
} BSTIterator;

// Hàm phụ trợ: Nhét tất cả các node bên nhánh trái vào Stack
void pushAllLeft(BSTIterator* obj, struct TreeNode* node) {
    while (node != NULL) {
        obj->top++;
        obj->stack[obj->top] = node;
        node = node->left;
    }
}

// Khởi tạo Iterator
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    
    // Cấp phát bộ nhớ cho Stack. Kích thước 100,005 đủ cho cây lệch hoàn toàn (Worst-case)
    obj->stack = (struct TreeNode**)malloc(100005 * sizeof(struct TreeNode*));
    obj->top = -1;
    
    // Bắt đầu nhồi toàn bộ nhánh trái của root vào
    pushAllLeft(obj, root);
    
    return obj;
}

// Trả về giá trị tiếp theo
int bSTIteratorNext(BSTIterator* obj) {
    // 1. Lấy node nhỏ nhất hiện tại trên đỉnh Stack
    struct TreeNode* minNode = obj->stack[obj->top];
    obj->top--;
    
    // 2. Nếu node này có nhánh phải, xử lý toàn bộ nhánh trái của nhánh phải đó
    if (minNode->right != NULL) {
        pushAllLeft(obj, minNode->right);
    }
    
    return minNode->val;
}

// Kiểm tra xem còn phần tử nào không
bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top >= 0;
}

// Dọn dẹp bộ nhớ
void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}