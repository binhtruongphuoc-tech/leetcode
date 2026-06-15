int lengthOfLongestSubstring(char * s) {
    int last_seen[128]; 
    
    for (int i = 0; i < 128; i++) {
        last_seen[i] = -1;
    }
    
    int max_len = 0;
    int left = 0;
    int right = 0;
    
    while (s[right] != '\0') {
        char current_char = s[right];
            if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }
                last_seen[current_char] = right;
                int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
            right++;
    }
    
    return max_len;
}