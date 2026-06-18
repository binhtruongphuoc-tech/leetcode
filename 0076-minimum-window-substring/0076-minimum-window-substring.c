

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    if (m < n || n == 0) {
        return "";
    }
        int map[128] = {0};
    for (int i = 0; i < n; i++) {
        map[t[i]]++;
    }
    
    int left = 0;
    int right = 0;
    int required = n; 
    int min_len = INT_MAX;
    int min_start = 0;
    
    while (right < m) {
        if (map[s[right]] > 0) {
            required--;
        }
        map[s[right]]--;
        
        while (required == 0) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_start = left;
            }
            
            map[s[left]]++;
            
            if (map[s[left]] > 0) {
                required++;
            }
            
            left++;
        }
        
        right++;
    }
    
    if (min_len == INT_MAX) {
        return "";
    }
    
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + min_start, min_len);
    result[min_len] = '\0';
    
    return result;
}