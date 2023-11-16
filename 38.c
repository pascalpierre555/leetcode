#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *countAndSay(int n) {
    char *output = calloc(512, sizeof(char));
    if (n == 1) {
        output[0] = '1';
        output[1] = 0;
    }
    else {
        char *input = countAndSay(n - 1);
        int idx = 0;
        int uni = 0;
        char tmp = input[0];
        for (int i = 1; input[i - 1] != 0; i++) {
            if (input[i] != tmp) {
                output[idx] = i - uni + '0';
                output[idx + 1] = input[i - 1];
                idx += 2;
                if (idx % 512 < 2) {
                    output = realloc(output, ((idx / 512) + 1) * 512 * sizeof(char));
                }
                tmp = input[i];
                uni = i;
            }
        }
        output[idx] = 0;
    }
    return output;
}
