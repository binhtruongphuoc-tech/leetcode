
void inorder(struct TreeNode* root, struct TreeNode** first, struct TreeNode** second, struct TreeNode** prev) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, first, second, prev);
    
    if (*prev != NULL && (*prev)->val > root->val) {
        if (*first == NULL) {
            *first = *prev;
            *second = root; 
        } 
        else {
            *second = root;
        }
    }
    
    *prev = root;
    
    inorder(root->right, first, second, prev);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    struct TreeNode* prev = NULL;
    
    inorder(root, &first, &second, &prev);
    
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}