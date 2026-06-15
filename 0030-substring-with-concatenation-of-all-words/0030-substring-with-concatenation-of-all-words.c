int cmp(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

typedef struct {
    const char* str;
    int expected;
} UWord;

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (!s || !words || wordsSize == 0) {
        return NULL;
    }

    int len_s = strlen(s);
    int len_w = strlen(words[0]);
    int total_len = len_w * wordsSize;

    if (len_s < total_len) {
        return NULL;
    }

    const char** sorted_words = (const char**)malloc(wordsSize * sizeof(const char*));
    for (int i = 0; i < wordsSize; i++) {
        sorted_words[i] = words[i];
    }
    qsort(sorted_words, wordsSize, sizeof(const char*), cmp);

    UWord* uwords = (UWord*)malloc(wordsSize * sizeof(UWord));
    int num_uwords = 0;

    uwords[0].str = sorted_words[0];
    uwords[0].expected = 1;
    num_uwords++;

    for (int i = 1; i < wordsSize; i++) {
        if (strcmp(sorted_words[i], sorted_words[i - 1]) == 0) {
            uwords[num_uwords - 1].expected++;
        } else {
            uwords[num_uwords].str = sorted_words[i];
            uwords[num_uwords].expected = 1;
            num_uwords++;
        }
    }

    int* result = (int*)malloc(len_s * sizeof(int));
    int* curr_count = (int*)malloc(num_uwords * sizeof(int));

    for (int i = 0; i < len_w; i++) {
        int left = i;
        int count = 0;
        memset(curr_count, 0, num_uwords * sizeof(int));

        for (int j = i; j <= len_s - len_w; j += len_w) {
            int id = -1;
            int l = 0, r = num_uwords - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int cmp_res = strncmp(s + j, uwords[mid].str, len_w);
                if (cmp_res == 0) {
                    id = mid;
                    break;
                } else if (cmp_res < 0) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (id != -1) {
                curr_count[id]++;
                count++;

                while (curr_count[id] > uwords[id].expected) {
                    int left_id = -1;
                    int ll = 0, rr = num_uwords - 1;
                    while (ll <= rr) {
                        int mid = ll + (rr - ll) / 2;
                        int cmp_res = strncmp(s + left, uwords[mid].str, len_w);
                        if (cmp_res == 0) {
                            left_id = mid;
                            break;
                        } else if (cmp_res < 0) {
                            rr = mid - 1;
                        } else {
                            ll = mid + 1;
                        }
                    }

                    curr_count[left_id]--;
                    count--;
                    left += len_w;
                }

                if (count == wordsSize) {
                    result[(*returnSize)++] = left;

                    int left_id = -1;
                    int ll = 0, rr = num_uwords - 1;
                    while (ll <= rr) {
                        int mid = ll + (rr - ll) / 2;
                        int cmp_res = strncmp(s + left, uwords[mid].str, len_w);
                        if (cmp_res == 0) {
                            left_id = mid;
                            break;
                        } else if (cmp_res < 0) {
                            rr = mid - 1;
                        } else {
                            ll = mid + 1;
                        }
                    }
                    curr_count[left_id]--;
                    count--;
                    left += len_w;
                }
            } else {
                memset(curr_count, 0, num_uwords * sizeof(int));
                count = 0;
                left = j + len_w;
            }
        }
    }

    free(sorted_words);
    free(uwords);
    free(curr_count);

    return result;
}