#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int len = strlen(s);
    int i2 = 0;
    char* tmp = (char*)calloc(len, sizeof(char));
    for (int i = 0; i < len; i++) {
        if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
            tmp[i2] = s[i];
            i2++;
        }
        else if ((i2 - 1 >= 0) && ((s[i] - 1 == tmp[i2 - 1]) || (s[i] - 2 == tmp[i2 - 1]))) {
            i2--;
            tmp[i2] = 0;
        }
        else {
            return 0;
        }
    }
    if (i2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {

}