#include <stdio.h>
#include <stdlib.h>

int romanToInt(char *s) {
    int i = 0;
    int output = 0;
    while (s[i]) {
        if (s[i] == 'M') {
            output += 1000;
        }
        else {
            break;
        }
        i++;
    }
    while (s[i]) {
        if (s[i] == 'C') {
            if (s[i + 1] == 'M') {
                output += 900;
                i++;
            }
            else if (s[i + 1] == 'D') {
                output += 400;
                i++;
            }
            else {
                output += 100;
            }
        }
        else if (s[i] == 'D') {
            output += 500;
        }
        else {
            break;
        }
        i++;
    }
    while (s[i]) {
        if (s[i] == 'X') {
            if (s[i + 1] == 'C') {
                output += 90;
                i++;
            }
            else if (s[i + 1] == 'L') {
                output += 40;
                i++;
            }
            else {
                output += 10;
            }
        }
        else if (s[i] == 'L') {
            output += 50;
        }
        else {
            break;
        }
        i++;
    }
    while (s[i]) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'X') {
                output += 9;
                i++;
            }
            else if (s[i + 1] == 'V') {
                output += 4;
                i++;
            }
            else {
                output += 1;
            }
        }
        else if (s[i] == 'V') {
            output += 5;
        }
        else {
            break;
        }
        i++;
    }
    return output;
}

int main() {
    return 0;
}