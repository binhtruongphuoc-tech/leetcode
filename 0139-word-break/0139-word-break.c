#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordBreak(char * s, char ** wordDict, int wordDictSize) {
    int len = strlen(s);
    
    bool* dp = (bool*)calloc(len + 1, sizeof(bool));
    
    dp[0] = true; 

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int w_len = strlen(wordDict[j]);
            
            if (i >= w_len && dp[i - w_len]) {
                
                if (strncmp(&s[i - w_len], wordDict[j], w_len) == 0) {
                    dp[i] = true; 
                    break;        
                }
            }
        }
    }

    bool result = dp[len];
    free(dp); 
    return result;
}