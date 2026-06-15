

char * countAndSay(int n) {
    int cap1 = 128, cap2 = 128;
    char *prev = (char *)malloc(cap1);
    char *curr = (char *)malloc(cap2);
    prev[0] = '1';
    prev[1] = '\0';
    
    for (int i = 2; i <= n; i++) {
        int len = 0;
        int j = 0;
        while (prev[j] != '\0') {
            int count = 1;
            while (prev[j] == prev[j + count]) count++;
            
            if (len + 2 >= cap2) {
                cap2 *= 2;
                curr = (char *)realloc(curr, cap2);
            }
            curr[len++] = count + '0';
            curr[len++] = prev[j];
            j += count;
        }
        curr[len] = '\0';
        
        char *temp = prev;
        prev = curr;
        curr = temp;
        
        int tempCap = cap1;
        cap1 = cap2;
        cap2 = tempCap;
    }
    
    free(curr);
    return prev;
}