char* getPermutation(int n, int k) {
    int fact[10];
    int nums[10];
    char* result = (char*)malloc((n + 1) * sizeof(char));
    
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        nums[i - 1] = i;
    }
    
    k--;
    for (int i = 1; i <= n; i++) {
        int index = k / fact[n - i];
        result[i - 1] = nums[index] + '0';
        k %= fact[n - i];
        
        for (int j = index; j < n - i; j++) {
            nums[j] = nums[j + 1];
        }
    }
    result[n] = '\0';
    
    return result;
}