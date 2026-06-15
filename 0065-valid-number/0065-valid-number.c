bool isNumber(char * s) {
    bool seenDigit = false;
    bool seenExponent = false;
    bool seenDot = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            seenDigit = true;
        } else if (s[i] == '+' || s[i] == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (seenExponent || !seenDigit) {
                return false;
            }
            seenExponent = true;
            seenDigit = false;
        } else if (s[i] == '.') {
            if (seenDot || seenExponent) {
                return false;
            }
            seenDot = true;
        } else {
            return false;
        }
    }

    return seenDigit;
}