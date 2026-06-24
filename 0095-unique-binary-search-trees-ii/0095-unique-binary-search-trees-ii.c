

struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    if (start > end) {
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[0] = NULL;
        *returnSize = 1; 
        return res;
    }
    
    int capacity = 10;
    struct TreeNode** res = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int count = 0;
    
    for (int i = start; i <= end; i++) {
        int leftSize = 0, rightSize = 0;
        
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, &leftSize);
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, &rightSize);
        
        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                
                if (count >= capacity) {
                    capacity *= 2;
                    res = (struct TreeNode**)realloc(res, capacity * sizeof(struct TreeNode*));
                }
                
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                
                res[count++] = root;
            }
        }
        free(leftTrees);
        free(rightTrees);
    }
    
    *returnSize = count;
    return res;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    return generateTreesHelper(1, n, returnSize);
}