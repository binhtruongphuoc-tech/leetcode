
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0; 
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->next != NULL && curr->val == curr->next->val) {
            
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            prev->next = curr->next;
            
        } else {
            prev = prev->next;
        }
        
        curr = curr->next;
    }
    
    return dummy.next;
}