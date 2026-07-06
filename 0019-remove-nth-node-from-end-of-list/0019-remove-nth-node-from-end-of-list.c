


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
        for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
        while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode* nodeToDelete = slow->next; 
    slow->next = slow->next->next;              
        free(nodeToDelete);
    
    struct ListNode* newHead = dummy->next;
    free(dummy);
    
    return newHead;
}