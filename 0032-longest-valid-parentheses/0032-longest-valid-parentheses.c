#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

int longestValidParentheses(char * s) {
    int left = 0, right = 0, maxlength = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            maxlength = MAX(maxlength, 2 * right);
        } else if (right >= left) {
            left = right = 0;
        }
    }
    
    left = right = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            maxlength = MAX(maxlength, 2 * left);
        } else if (left >= right) {
            left = right = 0;
        }
    }
    
    return maxlength;
}