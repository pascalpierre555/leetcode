#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canConstruct(char *ransomNote, char *magazine) {
    int letters[26] = {0};
    for (int i = 0; ransomNote[i] != 0; i++) {
        letters[ransomNote[i] - 'a']++;
    }
    for (int i = 0; magazine[i] != 0; i++) {
        letters[magazine[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i] > 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    return 0;
}