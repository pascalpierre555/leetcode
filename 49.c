#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAnagrams(char *a, char *b) {
    if (strlen(a) != strlen(b)) {
        return 0;
    }
    int letters[26] = {0};
    for (int i = 0; a[i] != 0; i++) {
        letters[a[i] - 'a']++;
    }
    for (int i = 0; b[i] != 0; i++) {
        letters[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            return 0;
        }
    }
    return 1;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    char ***output = NULL;
    *returnColumnSizes = 0;
    int size = 0;
    for (int i = 0; i < strsSize; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d %d\n", i, j);
            if (isAnagrams(strs[i], output[j][0])) {
                if (*returnColumnSizes[j] % 20 == 0) {
                    output[size] = realloc(output[size], (((*returnColumnSizes[j]) / 20) + 1) * 20 * sizeof(char *));
                }
                output[j][*returnColumnSizes[j]] = strs[i];
                (*returnColumnSizes[j])++;
                break;
            }
        }
        if (size % 512 == 0) {
            output = realloc(output, ((size / 512) + 1) * 512 * sizeof(char **));
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, 512 * sizeof(int));
            memset(*returnColumnSizes, 0, 512 * sizeof(int));
        }
        printf("mwoah");
        output[size] = (char **)malloc(20 * sizeof(char *));
        (*returnColumnSizes)[size] = 1;
        output[size][0] = strs[i];
        size++;
    }
    *returnSize = size;
    return output;
}