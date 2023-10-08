#include <stdio.h>
#include <stdlib.h>

int myAtoi(char *s) {
    int i = 0;
    int output = 0;
    int sign = 1;
    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == 45) {
        sign *= -1;
        i++;
    }
    else if (s[i] == 43) {
        i++;
    }
    while ((s[i] >= 48) && (s[i] <= 57)) {
        if ((__INT_MAX__ / 10 > output) || ((__INT_MAX__ / 10 == output) && (__INT_MAX__ % 10 >= s[i] - 48))) {
            output = (10 * output) + (s[i] - 48);
        }
        else if (sign == -1) {
            return -__INT_MAX__ - 1;
        }
        else {
            return __INT_MAX__;
        }
        i++;
    }
    output *= sign;
    return output;
}

int main() {
    char input[100] = {0};
    fgets(input, 100, stdin);
    int output = myAtoi(input);
    printf("%d", output);
}