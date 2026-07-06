
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    int curr = 0; 
    
    while (curr < wordsSize) {
        int next = curr + 1;
        int line_len_with_min_spaces = strlen(words[curr]);
        
        while (next < wordsSize && line_len_with_min_spaces + 1 + strlen(words[next]) <= maxWidth) {
            line_len_with_min_spaces += 1 + strlen(words[next]);
            next++;
        }
        
        int num_words = next - curr;
        int total_letters = 0;
        for (int i = curr; i < next; i++) {
            total_letters += strlen(words[i]);
        }
        int total_spaces = maxWidth - total_letters;
        
        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        int idx = 0;
        
        if (next == wordsSize || num_words == 1) {
            for (int i = curr; i < next; i++) {
                int len = strlen(words[i]);
                strcpy(line + idx, words[i]);
                idx += len;
                
                if (i < next - 1) {
                    line[idx++] = ' ';
                }
            }
            while (idx < maxWidth) {
                line[idx++] = ' ';
            }
        } 
        else {
            int base_spaces = total_spaces / (num_words - 1);
            int extra_spaces = total_spaces % (num_words - 1);
            
            for (int i = curr; i < next; i++) {
                int len = strlen(words[i]);
                strcpy(line + idx, words[i]);
                idx += len;
                
                if (i < next - 1) {
                    int spaces_to_add = base_spaces + ((i - curr) < extra_spaces ? 1 : 0);
                    for (int s = 0; s < spaces_to_add; s++) {
                        line[idx++] = ' ';
                    }
                }
            }
        }
        
        line[maxWidth] = '\0'; 
        res[*returnSize] = line;
        (*returnSize)++;
        
        curr = next;
    }
    
    return res;
}