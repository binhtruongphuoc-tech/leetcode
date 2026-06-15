#ifndef NULL
#define NULL ((void *)0)
#endif

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode *curr = head;
    struct ListNode *prev = &dummy;
    struct ListNode *nxt = NULL;
    int count = 0;
    
    while (curr) {
        count++;
        curr = curr->next;
    }
    
    while (count >= k) {
        curr = prev->next;
        nxt = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        prev = curr;
        count -= k;
    }
    
    return dummy.next;
}