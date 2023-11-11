#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int is = 0, ip = 0;
    int ls = strlen(s);
    int lp = strlen(p);
    int i1, i2;
    while ((is < ls) && (ip < lp)) {
        if ((p[ip] == '?') || (s[is] == p[ip])) {
            is++;
            ip++;
        }
        else if (p[ip] == '*') {
            ip++;
            if (ip >= lp) {
                return 1;
            }
            i2 = 0;
            i1 = 0;
            while ((is < ls) && (ip < lp)) {
                is -= i1;
                ip -= i2;
                i2 = 0;
                while ((is < ls) && (s[is] != p[ip])) {
                    is++;
                }
                while (((is < ls) && (ip < lp)) && ((p[ip] == '?') || (s[is] == p[ip]))) {
                    is++;
                    ip++;
                    i2++;
                }
                i1 = i2 - 1;
                if (p[ip] == '*') {
                    break;
                }
            }
        }
        else {
            break;
        }
    }
    while ((ip < lp) && (p[ip] == '*')) {
        ip++;
    }
    if ((is >= ls) && (ip >= lp)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char a[20];
    char b[20];
    scanf("%s %s", a, b);
    int output = isMatch(a, b);
    printf("%d", output);
    return 0;
}