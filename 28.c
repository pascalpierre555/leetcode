#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPS(char *needle, int *lps, int ln) {
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < ln) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len > 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    return;
}

int strStr(char *haystack, char *needle) {
    int lh = strlen(haystack);
    int ln = strlen(needle);
    int *lps = (int *)malloc(ln * sizeof(int));
    int ih = 0, in = 0;
    computeLPS(needle, lps, ln);
    while (ih < lh) {
        if (haystack[ih] == needle[in]) {
            ih++;
            in++;
        }
        else if (in < ln) {
            if (in != 0) {
                in = lps[in - 1];
            }
            else {
                ih++;
            }
        }
        if (in == ln) {
            return ih - in;
        }
    }
    return -1;
}

int main() {
    const char haystack[20] = "TutorialsYiibai";
    const char needle[10] = "Yiibai";
    char *ret;

    ret = strstr(haystack, needle);

    printf("The substring is: %d", haystack);
    printf("The substring is: %d", ret);
    printf("The substring is: %d", needle);
    return 0;
}