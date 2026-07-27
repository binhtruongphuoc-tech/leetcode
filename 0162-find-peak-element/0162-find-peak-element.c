int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // So sánh phần tử giữa với phần tử ngay bên phải nó
        if (nums[mid] < nums[mid + 1]) {
            // Đang lên dốc: Đỉnh nằm ở bên phải
            left = mid + 1;
        } else {
            // Đang xuống dốc (hoặc đứng trên đỉnh): Đỉnh nằm ở bên trái hoặc chính là mid
            right = mid;
        }
    }
    
    // Khi left == right, ta đã bị kẹp chặt vào một đỉnh
    return left;
}