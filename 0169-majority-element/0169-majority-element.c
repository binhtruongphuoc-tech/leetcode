int majorityElement(int* nums, int numsSize) {
    int candidate = 0;
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Nếu lực lượng về 0, đổi ứng viên mới
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } 
        // Nếu gặp người cùng phe, tăng quân số
        else if (nums[i] == candidate) {
            count++;
        } 
        // Nếu gặp phe khác, triệt tiêu lẫn nhau
        else {
            count--;
        }
    }
    
    return candidate;
}