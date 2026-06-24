/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }
    
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    
    struct ListNode* curr = prev->next;
    
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next_node = curr->next; 
        
        curr->next = next_node->next;            
        next_node->next = prev->next;            
        prev->next = next_node;                  
    }
    
    return dummy.next;
}