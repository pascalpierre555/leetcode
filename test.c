#include <stdio.h>
#include <string.h>

#define SIZE 40

int main(void) {
    char *source = malloc(SIZE * sizeof(char));
    strcpy(source, "abcdefgh");
    char source1[SIZE] = "123456789";
    char destination[SIZE] = "abcdefg";
    char destination1[SIZE] = "abcdefg";
    char *return_string;
    int index = 5;

    /* This is how strcpy works */
    printf("destination is originally = '%s'\n", destination);
    return_string = strcpy(destination, source);
    printf("After strcpy, destination becomes '%s'\n\n", destination);

    /* This is how strncpy works */
    printf("destination1 is originally = '%s'\n", destination1);
    return_string = strncpy(destination1, source + 2, index);
    printf("After strncpy, destination1 becomes '%s'\n", destination1);
}
