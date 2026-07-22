/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Giai đoạn 1: Xác định xem có chu trình hay không
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        // Nếu gặp nhau, chắc chắn có chu trình -> Chuyển sang Giai đoạn 2
        if (slow == fast) {
            // Đưa Thỏ (hoặc một con trỏ mới) về lại vạch xuất phát
            struct ListNode *entry = head;
            
            // Cho cả 2 đi cùng tốc độ 1 bước, gặp nhau ở đâu thì đó là đầu chu trình
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            
            return entry; // Trả về node bắt đầu chu trình
        }
    }
    
    // Nếu fast chạy đến NULL nghĩa là đường thẳng, không có chu trình
    return NULL;
}