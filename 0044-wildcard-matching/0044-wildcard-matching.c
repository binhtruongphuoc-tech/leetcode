bool isMatch(char * s, char * p) {
    int i = 0;
    int j = 0;
    int star_idx = -1;
    int match = -1;

    while (s[i] != '\0') {
        if (p[j] == s[i] || p[j] == '?') {
            i++;
            j++;
        } else if (p[j] == '*') {
            star_idx = j;
            match = i;
            j++;
        } else if (star_idx != -1) {
            j = star_idx + 1;
            match++;
            i = match;
        } else {
            return false;
        }
    }

    while (p[j] == '*') {
        j++;
    }

    return p[j] == '\0';
}