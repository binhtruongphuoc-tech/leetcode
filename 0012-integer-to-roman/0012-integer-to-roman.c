#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    const char* M[] = {"", "M", "MM", "MMM"};
    const char* C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const char* X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const char* I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char* result = (char*)malloc(16 * sizeof(char));
    sprintf(result, "%s%s%s%s", 
            M[num / 1000], 
            C[(num % 1000) / 100], 
            X[(num % 100) / 10], 
            I[num % 10]);

    return result;
}
