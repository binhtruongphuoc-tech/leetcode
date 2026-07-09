/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>

int maxGain(struct TreeNode* node, int* maxSum) {
    if (node == NULL) {
        return 0;
    }

    int leftGain = maxGain(node->left, maxSum);
    if (leftGain < 0) leftGain = 0;
    
    int rightGain = maxGain(node->right, maxSum);
    if (rightGain < 0) rightGain = 0;

    int currentPathSum = node->val + leftGain + rightGain;

    if (currentPathSum > *maxSum) {
        *maxSum = currentPathSum;
    }

    return node->val + (leftGain > rightGain ? leftGain : rightGain);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    
    maxGain(root, &maxSum);
    
    return maxSum;
}