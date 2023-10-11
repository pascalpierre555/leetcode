#include <stdio.h>
#include <stdlib.h>

struct node {
    char val;
    struct node *next;
};

struct node *insterNode(char val, struct node *back) {
    struct node *next = (struct node *)malloc(sizeof(struct node));
    next->val = val;
    next->next = NULL;
    if (back != NULL) {
        next->next = back;
    }
    return next;
}

struct node *insertRoman(int num, int digit, char symbol[4][2], struct node *curr) {
    if (num % 5 == 4) {
        if (num == 4) {
            curr = insterNode(symbol[digit][1], curr);
        }
        else {
            curr = insterNode(symbol[digit + 1][0], curr);
        }
        curr = insterNode(symbol[digit][0], curr);
        return curr;
    }
    for (int i = 0; i < (num % 5); i++) {
        curr = insterNode(symbol[digit][0], curr);
    }
    for (int i = 0; i < (num / 5); i++) {
        curr = insterNode(symbol[digit][1], curr);
    }
    return curr;
}

char *intToRoman(int num) {
    char symbol[4][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', '\0'}};
    char *output = (char *)malloc(16 * sizeof(char));
    struct node *head = NULL;
    int a = 0;
    for (int i = 0; num > 0; i++) {
        a = num % 10;
        num /= 10;
        head = insertRoman(a, i, symbol, head);
    }
    int i = 0;
    for (i = 0; head != NULL; i++) {
        output[i] = head->val;
        head = head->next;
    }
    output[i] = '\0';
    return output;
}

int main() {
    int input;
    scanf("%d", &input);
    char *output = calloc(16, sizeof(char));
    output = intToRoman(input);
    printf("%s", output);
    return 0;
}