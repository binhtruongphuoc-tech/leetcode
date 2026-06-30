/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd, 
                                 int* postorder, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = NULL;
    root->right = NULL;
    
    (*postIndex)--;

    if (inStart == inEnd) {
        return root;
    }

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    root->right = buildTreeHelper(inorder, inIndex + 1, inEnd, postorder, postIndex);
    
    root->left = buildTreeHelper(inorder, inStart, inIndex - 1, postorder, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, &postIndex);
}