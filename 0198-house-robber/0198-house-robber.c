int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int prev2 = 0; 
    int prev1 = 0; 
    
    for (int i = 0; i < numsSize; i++) {
        int current = (prev2 + nums[i] > prev1) ? (prev2 + nums[i]) : prev1;
            prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}