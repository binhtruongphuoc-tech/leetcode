/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stddef.h>

bool hasCycle(struct ListNode *head) {
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử (không trỏ đi đâu), chắc chắn không có chu trình
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Điều kiện dừng: fast chạm đến điểm kết thúc (NULL)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Rùa đi 1 bước
        fast = fast->next->next;    // Thỏ đi 2 bước
        
        // Nếu Rùa và Thỏ gặp nhau, chứng tỏ có chu trình
        if (slow == fast) {
            return true;
        }
    }
    
    // Thỏ đã chạy đến vạch đích NULL
    return false;
}