

int expandAroundCenter(char * s, int left, int right) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char * longestPalindrome(char * s) {
    if (s == NULL || s[0] == '\0') return "";
    
    int start = 0, end = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int max_len = len1 > len2 ? len1 : len2;
        
        if (max_len > end - start) {
            start = i - (max_len - 1) / 2;
            end = i + max_len / 2;
        }
    }
    
    int final_len = end - start + 1;
    char * res = (char *)malloc(final_len + 1);
    strncpy(res, s + start, final_len);
    res[final_len] = '\0';
    
    return res;
}