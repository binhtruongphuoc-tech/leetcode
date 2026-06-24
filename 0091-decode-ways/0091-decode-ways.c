#include <string.h>

int numDecodings(char* s) {
    if (s == NULL || s[0] == '0') {
        return 0;
    }
    
    int n = strlen(s);
    
    int dp2 = 1; 
    int dp1 = 1; 
    
    for (int i = 1; i < n; i++) {
        int current = 0; 
        
        if (s[i] != '0') {
            current += dp1;
        }
        
        int twoDigit = (s[i-1] - '0') * 10 + (s[i] - '0');
        
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += dp2;
        }
        
        dp2 = dp1;
        dp1 = current;
    }
    
    return dp1;
}