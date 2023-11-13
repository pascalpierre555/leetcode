#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *s, char *p) {
    int ls = strlen(s);
    int lp = strlen(p);
    int i1 = 0, i2 = 0;
    if ((ls == 0) && (lp == 0)) {
        return 0;
    }
    for (int i = 0; i < ls; i++) {
        i1 = i;
        while ((i1 < ls) && (i2 < lp) && ((s[i1] == p[i2]) || (p[i2] == '?'))) {
            i1++;
            i2++;
        }
        if (i2 == lp) {
            return i;
        }
        i2 = 0;
    }
    return -1;
}

bool isMatch(char *s, char *p) {
    int ls = strlen(s);
    int lp = strlen(p);
    char *s2 = calloc((ls + 1), sizeof(char));
    char *p2 = calloc((lp + 1), sizeof(char));
    int starl = -1, starr = lp, starm = 0;
    int idxs = 0;
    for (int i = 0; i < lp; i++) {
        if (p[i] == '*') {
            starl = i;
            ls -= i;
            break;
        }
        else if ((i < ls) && (s[i] != p[i]) && (p[i] != '?')) {
            return 0;
        }
        else if (i >= ls) {
            return 0;
        }
    }
    if (starl == -1) {
        if ((find(s, p) == 0) && (ls == lp)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    strncpy(s2, s + starl, ls);
    strcpy(s, s2);
    strncpy(p2, p + starl, lp - starl);
    strcpy(p, p2);
    lp -= starl;
    starl = 0;
    for (int i = 0; i < lp; i++) {
        if (p[lp - 1 - i] == '*') {
            starr = lp - 1 - i;
            ls -= (lp - 1 - starr);
            break;
        }
        else if ((ls - 1 - i >= 0) && (s[ls - 1 - i] != p[lp - 1 - i]) && (p[lp - 1 - i] != '?')) {
            return 0;
        }
    }
    idxs = starl;
    for (int i = starl + 1; i <= starr; i++) {
        if (p[i] == '*') {
            starm = i;
            memset(s2, 0, (ls + 1) * sizeof(char));
            memset(p2, 0, (lp + 1) * sizeof(char));
            if (ls >= 0) {
                strncpy(s2, s + idxs, ls);
                strncpy(p2, p + starl + 1, starm - starl - 1);
            }
            if (find(s2, p2) >= 0) {
                idxs += (find(s2, p2) + strlen(p2));
                ls -= (find(s2, p2) + strlen(p2));
                starl = starm;
            }
            else {
                return 0;
            }
        }
    }
    if (ls >= 0) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    char a[20] = "b";
    char b[20] = "?*?";
    // scanf("%s %s", a, b);
    int output = isMatch(a, b);
    printf("%d", output);
    return 0;
}