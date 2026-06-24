bool isValidBSTHelper(struct TreeNode* node, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (node == NULL) {
        return true;
    }
    
    if (minNode != NULL && node->val <= minNode->val) {
        return false;
    }
    
    if (maxNode != NULL && node->val >= maxNode->val) {
        return false;
    }
    
    return isValidBSTHelper(node->left, minNode, node) && 
           isValidBSTHelper(node->right, node, maxNode);
}

bool isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, NULL, NULL);
}