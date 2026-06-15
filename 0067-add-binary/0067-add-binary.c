char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int maxLen = i > j ? i : j;
    maxLen++;
    char* result = (char*)malloc(maxLen + 2);
    result[maxLen + 1] = '\0';
    
    int carry = 0;
    int k = maxLen;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0'; 
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        
        result[k] = (sum % 2) + '0'; 
        carry = sum / 2;
        k--;
    }
    if (k == 0) {
        memmove(result, result + 1, maxLen + 1);
    }
    return result;
}
