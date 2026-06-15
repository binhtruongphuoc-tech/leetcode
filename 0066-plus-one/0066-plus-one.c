int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    *returnSize = digitsSize + 1;
    int* newDigits = (int*)malloc((*returnSize) * sizeof(int));
    newDigits[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        newDigits[i] = 0;
    }  
    return newDigits;
}
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
}
