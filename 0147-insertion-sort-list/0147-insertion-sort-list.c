/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode* insertionSortList(struct ListNode* head) {
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử thì đã tự sắp xếp
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Tạo dummy node làm mỏ neo ở đầu danh sách
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0; // Giá trị không quan trọng
    dummy->next = head;

    struct ListNode* lastSorted = head;     // Node cuối cùng của phần đã sắp xếp
    struct ListNode* curr = head->next;     // Node đang xét để chèn

    while (curr != NULL) {
        // Trường hợp 1: Nếu giá trị curr lớn hơn hoặc bằng phần tử lớn nhất đã sắp xếp
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next; // Mở rộng vùng đã sắp xếp
        } 
        // Trường hợp 2: Cần chèn curr vào đâu đó ở phía trước
        else {
            struct ListNode* prev = dummy;
            
            // Tìm vị trí thích hợp (prev sẽ dừng lại ngay trước vị trí cần chèn)
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // Thực hiện cắt/nối để chèn curr vào sau prev
            lastSorted->next = curr->next; // Tách curr ra khỏi danh sách gốc
            curr->next = prev->next;       // Nối curr trỏ đến node tiếp theo của prev
            prev->next = curr;             // Nối prev trỏ đến curr
        }
        
        // Di chuyển curr sang phần tử tiếp theo cần xét
        curr = lastSorted->next;
    }

    // Lưu lại head mới và giải phóng dummy node
    struct ListNode* sortedHead = dummy->next;
    free(dummy);
    
    return sortedHead;
}