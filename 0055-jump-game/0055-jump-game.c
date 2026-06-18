
#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false;
        }
        
        maxReach = MAX(maxReach, i + nums[i]);
        
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }
    
    return true;
}