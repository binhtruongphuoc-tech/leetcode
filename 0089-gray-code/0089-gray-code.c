int* grayCode(int n, int* returnSize) {
    int totalElements = 1 << n; 
        *returnSize = totalElements;
        int* result = (int*)malloc(totalElements * sizeof(int));
        for (int i = 0; i < totalElements; i++) {
        result[i] = i ^ (i >> 1);
    }   
    return result;
}