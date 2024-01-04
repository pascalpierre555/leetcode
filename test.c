#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[80] = "This is - www.runoob.com - website";
    const char s[2] = "-";
    char **str2 = (char **)malloc(3 * sizeof(char *));
    char *token;
    int i = 0;
    /* 获取第一个子字符串 */
    token = strtok(str, s);
    str2[i] = token;

    /* 继续获取其他的子字符串 */
    while (token != NULL) {
        printf("%s\n", str2[i]);
        i++;
        token = strtok(NULL, s);
        str2[i] = token;
    }

    return (0);
}