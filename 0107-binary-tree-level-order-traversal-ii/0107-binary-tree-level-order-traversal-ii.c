
#include <stdlib.h>

int getDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}


 
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int depth = getDepth(root);
    *returnSize = depth;
    
    int** result = (int**)malloc(depth * sizeof(int*));
    *returnColumnSizes = (int*)malloc(depth * sizeof(int));

    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;

    queue[tail++] = root;
    
    int currentLevel = depth - 1; 

    while (head < tail) {
        int levelSize = tail - head; 
        
        (*returnColumnSizes)[currentLevel] = levelSize;
        result[currentLevel] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            result[currentLevel][i] = node->val; 

            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        
        currentLevel--; 
    }

    free(queue);
    return result;
}