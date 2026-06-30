
#include <stddef.h>

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* head = root; 
    
    while (head != NULL) {
        struct Node dummy;
        dummy.next = NULL;
        
        struct Node* tail = &dummy;
        
        struct Node* curr = head;
        
        while (curr != NULL) {
            if (curr->left != NULL) {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right != NULL) {
                tail->next = curr->right;
                tail = tail->next;
            }
            curr = curr->next;
        }
        
        head = dummy.next;
    }
    
    return root;
}