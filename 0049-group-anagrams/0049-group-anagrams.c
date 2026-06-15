int cmpChar(const void* a, const void* b) {
    return *(const char*)a - *(const char*)b;
}

typedef struct {
    char* original; 
    char* sorted;   
} Pair;

int cmpPair(const void* a, const void* b) {
    Pair* pa = (Pair*)a;
    Pair* pb = (Pair*)b;
    return strcmp(pa->sorted, pb->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (strsSize == 0) return NULL;
    Pair* pairs = (Pair*)malloc(strsSize * sizeof(Pair));
    for (int i = 0; i < strsSize; i++) {
        pairs[i].original = strs[i];
                int len = strlen(strs[i]);
        pairs[i].sorted = (char*)malloc((len + 1) * sizeof(char));
        strcpy(pairs[i].sorted, strs[i]);
                qsort(pairs[i].sorted, len, sizeof(char), cmpChar);
    }

    qsort(pairs, strsSize, sizeof(Pair), cmpPair);

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    
    for (int i = 0; i < strsSize; i++) {
        if (i == 0 || strcmp(pairs[i].sorted, pairs[i - 1].sorted) != 0) {
            result[*returnSize] = (char**)malloc(strsSize * sizeof(char*)); 
            (*returnColumnSizes)[*returnSize] = 0; 
            (*returnSize)++; 
        }
            int currentGroupIndex = *returnSize - 1;
        int currentItemIndex = (*returnColumnSizes)[currentGroupIndex];
        
        result[currentGroupIndex][currentItemIndex] = pairs[i].original;
        (*returnColumnSizes)[currentGroupIndex]++; 
    }
    for (int i = 0; i < strsSize; i++) {
        free(pairs[i].sorted);
    }
    free(pairs);

    return result;
}