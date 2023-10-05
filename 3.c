#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int temp = 0, max = 0;
    int letters[128] = {0};
    for (int i = 0; s[i] != '\n'; i++) {
        if ((letters[s[i]] != 0) && (letters[s[i]] > temp)) {
            temp = letters[s[i]];
        }
        if ((i - temp + 1) > max) {
            max = i - temp + 1;
        }
        letters[s[i]] = i + 1;
    }
    return max;
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    int max = lengthOfLongestSubstring(s);
    printf("%d", max);
    return 0;
}