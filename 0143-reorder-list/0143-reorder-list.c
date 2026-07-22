/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stddef.h>

void reorderList(struct ListNode* head) {
    // Nếu danh sách rỗng, có 1 hoặc 2 phần tử thì không cần sắp xếp lại
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }
    
    // BƯỚC 1: Tìm điểm giữa bằng Rùa và Thỏ
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // Dừng khi fast ở node cuối hoặc áp chót
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // BƯỚC 2: Đảo ngược nửa sau của danh sách
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    
    // Ngắt nửa đầu khỏi nửa sau để tránh tạo chu trình
    slow->next = NULL; 
    
    // Thuật toán đảo ngược danh sách (Reverse Linked List)
    while (curr != NULL) {
        struct ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    // BƯỚC 3: Trộn đan xen 2 nửa danh sách
    struct ListNode *first = head;
    struct ListNode *second = prev; // prev lúc này là đầu của nửa sau đã bị lật
    
    while (second != NULL) {
        // Lưu tạm các node tiếp theo
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;
        
        // Thực hiện nối chéo
        first->next = second;
        second->next = temp1;
        
        // Tiến 2 con trỏ lên bước tiếp theo
        first = temp1;
        second = temp2;
    }
}