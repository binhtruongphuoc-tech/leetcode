

char * multiply(char * num1, char * num2) {
    if (num1[0] == '0' || num2[0] == '0') {
        char *zero = (char *)malloc(2 * sizeof(char));
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *vals = (int *)calloc(len1 + len2, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + vals[p2];

            vals[p2] = sum % 10;
            vals[p1] += sum / 10;
        }
    }

    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    int index = 0;
    int i = 0;

    while (i < len1 + len2 && vals[i] == 0) {
        i++;
    }

    while (i < len1 + len2) {
        result[index++] = vals[i++] + '0';
    }
    result[index] = '\0';

    free(vals);
    return result;
}