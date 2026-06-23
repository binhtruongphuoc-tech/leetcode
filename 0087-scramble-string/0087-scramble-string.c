#include <string.h>
#include <stdbool.h>

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    
    if (n != m) return false;
    if (n == 0) return true;


    bool dp[31][30][30] = {false};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s1[i] == s2[j]) {
                dp[1][i][j] = true;
            }
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            for (int j = 0; j <= n - len; j++) {
                
                for (int k = 1; k < len; k++) {

                    bool no_swap = dp[k][i][j] && dp[len - k][i + k][j + k];
                    

                    bool swap = dp[k][i][j + len - k] && dp[len - k][i + k][j];
                    
                    if (no_swap || swap) {
                        dp[len][i][j] = true;
                        break; 
                    }
                }
                
            }
        }
    }

    return dp[n][0][0];
}