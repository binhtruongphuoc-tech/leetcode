

#include <stddef.h>

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* leftmost = root;
    
    while (leftmost->left != NULL) {
        struct Node* curr = leftmost;
        
        while (curr != NULL) {
            curr->left->next = curr->right;
            
            if (curr->next != NULL) {
                curr->right->next = curr->next->left;
            }
            
            curr = curr->next;
        }
        
        leftmost = leftmost->left;
    }
    
    return root;
}