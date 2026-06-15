int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    long long absDividend = llabs((long long)dividend);
    long long absDivisor = llabs((long long)divisor);
    long long result = 0;

    while (absDividend >= absDivisor) {
        long long temp = absDivisor;
        long long multiple = 1;
        
        while (absDividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        
        absDividend -= temp;
        result += multiple;
    }

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    
    return sign == 1 ? result : -result;
}