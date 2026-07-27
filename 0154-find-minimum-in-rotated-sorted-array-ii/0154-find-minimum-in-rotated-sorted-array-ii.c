int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[right]) {
            // Nửa phải được sắp xếp chuẩn, phần tử nhỏ nhất ở nửa trái
            right = mid;
        } 
        else if (nums[mid] > nums[right]) {
            // Đứt gãy nằm ở nửa phải, phần tử nhỏ nhất chắc chắn ở bên phải mid
            left = mid + 1;
        } 
        else {
            // nums[mid] == nums[right]: Gặp phần tử trùng lặp
            // Loại bỏ dần phần tử ở rìa phải một cách an toàn
            right--;
        }
    }
    
    // Khi vòng lặp kết thúc, left hội tụ về phần tử nhỏ nhất
    return nums[left];
}