#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = (int*)malloc(40 * sizeof(int));
    int size = sizeof(i);
    printf("%d", size);
    return 0;
}