

char * simplifyPath(char * path) {
    int max_len = strlen(path);
    
    char** stack = (char**)malloc(max_len * sizeof(char*));
    int top = -1;
    
    char* token = strtok(path, "/");
    
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
        } 
        else if (strcmp(token, "..") == 0) {
            if (top >= 0) {
                top--;
            }
        } 
        else {
            stack[++top] = token;
        }
        
        token = strtok(NULL, "/");
    }
    
    char* res = (char*)malloc((max_len + 1) * sizeof(char));
    
    if (top == -1) {
        res[0] = '/';
        res[1] = '\0';
    } else {
        int len = 0;
        for (int i = 0; i <= top; i++) {
            res[len++] = '/';
            strcpy(res + len, stack[i]);
            len += strlen(stack[i]);
        }
        res[len] = '\0'; 
    }
    
    free(stack);
    return res;
}