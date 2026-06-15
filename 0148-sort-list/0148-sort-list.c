

// Hàm trộn (merge) hai danh sách liên kết đã sắp xếp
struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    // Sử dụng một node giả (dummy) để làm điểm tựa nối các node
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    // So sánh và nối node có giá trị nhỏ hơn vào tail
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Nếu một trong hai danh sách vẫn còn phần tử, nối toàn bộ phần còn lại
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Hàm tìm điểm giữa của danh sách liên kết
struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Hàm chính: Sắp xếp danh sách
struct ListNode* sortList(struct ListNode* head) {
    // Điều kiện dừng: Danh sách rỗng hoặc chỉ có 1 phần tử (đã tự sắp xếp)
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Chia danh sách làm hai nửa
    struct ListNode* mid = getMid(head);
    struct ListNode* rightHead = mid->next;
    mid->next = NULL; // Cắt đứt liên kết

    // Gọi đệ quy để sắp xếp từng nửa
    struct ListNode* leftSorted = sortList(head);
    struct ListNode* rightSorted = sortList(rightHead);

    // Trộn hai nửa đã sắp xếp và trả về
    return merge(leftSorted, rightSorted);
}