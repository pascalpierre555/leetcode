#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkPalindrome(int i, int j, bool **dp, char *s) {
    if (i == j) {
        dp[i][j] = 1;
        return (i - j);
    }
    else if ((i - j == 1) && (s[i] == s[j])) {
        dp[i][j] = 1;
        return (i - j);
    }
    else if ((dp[i - 1][j + 1] == 1) && (s[i] == s[j])) {
        dp[i][j] = 1;
        return (i - j);
    }
    else {
        return 0;
    }
}

char *longestPalindrome(char *s) {
    int len = strlen(s);
    int start = 0;
    int max = 0;
    int pLen = 0;
    bool **dp = (bool **)malloc(len * sizeof(bool *));
    for (int i = 0; i < len; i++) {
        dp[i] = (bool *)calloc(i + 1, sizeof(bool));
        for (int j = 0; j < i + 1; j++) {
            pLen = checkPalindrome(i, j, dp, s) + 1;
            if (pLen > max) {
                max = pLen;
                start = j;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        free(dp[i]);
    }
    free(dp);
    char *output = (char *)malloc((max + 1) * sizeof(char));
    strncpy(output, &s[start], max);
    output[max] = '\0';
    return output;
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    int a = strlen(s);
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
    printf("%d", a);

    char *output = longestPalindrome(s);
    printf("%s", output);
    free(output);
    return 0;
}