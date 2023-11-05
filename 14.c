#include <stdio.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    char *output = calloc(201, sizeof(char));
    for (int i = 0; i < 200; i++) {
        if (strs[0][i]) {
            int j = 0;
            while ((j < strsSize) && (strs[j][i]) && (strs[j][i] == strs[0][i])) {
                j++;
            }
            if (j == strsSize) {
                output[i] = strs[0][i];
            }
            else {
                return output;
            }
        }
        else {
            return output;
        }
    }
    return output;
}

int main() {
    int strsSize;
    scanf("%d", &strsSize);
    char **input = (char **)calloc(strsSize, sizeof(char *));
    for (int i = 0; i < strsSize; i++) {
        input[i] = calloc(200, sizeof(char));
        fgets(input[i], 200, stdin);
        printf("%d", i);
    }
    char *output = (char *)calloc(201, sizeof(char));
    output = longestCommonPrefix(input, strsSize);
    printf("%s", output);
}