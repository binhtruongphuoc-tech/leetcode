#include <string.h>

int numDistinct(char * s, char * t) {
    int m = strlen(s);
    int n = strlen(t);
    
    if (n > m) {
        return 0;
    }
    
    unsigned long long dp[n + 1];
    
    dp[0] = 1; 
    for (int j = 1; j <= n; j++) {
        dp[j] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }
    
    return (int)dp[n];
}