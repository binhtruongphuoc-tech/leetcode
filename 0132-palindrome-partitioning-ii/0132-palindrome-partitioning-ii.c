
int minCut(char * s) {
    int n = strlen(s);
    if (n <= 1) return 0;
    
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = i; 
    }
    
    for (int i = 0; i < n; i++) {
        
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (left == 0) {
                dp[right] = 0; 
            } else {
                if (dp[left - 1] + 1 < dp[right]) {
                    dp[right] = dp[left - 1] + 1;
                }
            }
            left--;
            right++;
        }
        
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (left == 0) {
                dp[right] = 0;
            } else {
                if (dp[left - 1] + 1 < dp[right]) {
                    dp[right] = dp[left - 1] + 1;
                }
            }
            left--;
            right++;
        }
    }
    
    return dp[n - 1];
}