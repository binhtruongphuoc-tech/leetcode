int titleToNumber(char * columnTitle) {
    int result = 0;
        while (*columnTitle != '\0') {
        int currentValue = *columnTitle - 'A' + 1;
                result = result * 26 + currentValue;
        
        columnTitle++;
    }    
    return result;
}