
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode lessDummy;
    struct ListNode greaterDummy;
    
    lessDummy.val = 0; lessDummy.next = NULL;
    greaterDummy.val = 0; greaterDummy.next = NULL;
    
    struct ListNode* less = &lessDummy;
    struct ListNode* greater = &greaterDummy;
    
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val < x) {
            less->next = curr;
            less = less->next;
        } else {
            greater->next = curr;
            greater = greater->next;
        }
        curr = curr->next;
    }
    
    greater->next = NULL;
    
    less->next = greaterDummy.next;
    
    return lessDummy.next;
}