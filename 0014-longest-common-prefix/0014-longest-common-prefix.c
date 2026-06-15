#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    // Duyệt qua từng ký tự của chuỗi đầu tiên
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char current_char = strs[0][i];
        
        for (int j = 1; j < strsSize; j++) {
           
            if (strs[j][i] == '\0' || strs[j][i] != current_char) {
                strs[0][i] = '\0';
                return strs[0]; 
            }
        }
    }
    
    return strs[0];
}