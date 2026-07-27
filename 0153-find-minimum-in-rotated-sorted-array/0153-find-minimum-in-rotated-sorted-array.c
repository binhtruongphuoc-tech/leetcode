int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    // Thu hẹp phạm vi cho đến khi chỉ còn 1 phần tử
    while (left < right) {
        // Nếu đoạn hiện tại đã được sắp xếp chuẩn chỉ, trả về ngay phần tử đầu
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        
        // Nếu nửa trái hoàn hảo, điểm đứt gãy nằm ở nửa phải
        if (nums[mid] >= nums[left]) {
            left = mid + 1;
        } 
        // Nếu nửa phải hoàn hảo, điểm đứt gãy nằm ở nửa trái (hoặc chính là mid)
        else {
            right = mid;
        }
    }
    
    // Khi vòng lặp kết thúc (left == right), ta đã khóa được mục tiêu
    return nums[left];
}