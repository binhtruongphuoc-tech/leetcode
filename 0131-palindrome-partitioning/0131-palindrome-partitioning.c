
bool isPalindrome(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void backtrack(char* s, int start, int len, char** path, int pathLen, 
               char**** res, int* returnSize, int** returnColumnSizes, int* capacity) {
    
    if (start == len) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = (char***)realloc(*res, *capacity * sizeof(char**));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, *capacity * sizeof(int));
        }
        
        (*res)[*returnSize] = (char**)malloc(pathLen * sizeof(char*));
        for (int i = 0; i < pathLen; i++) {
            int strSize = strlen(path[i]);
            (*res)[*returnSize][i] = (char*)malloc((strSize + 1) * sizeof(char));
            strcpy((*res)[*returnSize][i], path[i]);
        }
        
        (*returnColumnSizes)[*returnSize] = pathLen;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < len; i++) {
        if (isPalindrome(s, start, i)) {
            int subLen = i - start + 1;
            char* subStr = (char*)malloc((subLen + 1) * sizeof(char));
            strncpy(subStr, s + start, subLen);
            subStr[subLen] = '\0'; 
            
            path[pathLen] = subStr;
            backtrack(s, i + 1, len, path, pathLen + 1, res, returnSize, returnColumnSizes, capacity);
            
            free(subStr);
        }
    }
}


char *** partition(char * s, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int len = strlen(s);
    
    int capacity = 1000;
    char*** res = (char***)malloc(capacity * sizeof(char**));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    
    char* path[16];
    
    backtrack(s, 0, len, path, 0, &res, returnSize, returnColumnSizes, &capacity);
    
    return res;
}