#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int a = 0, output = 0;
    while (x) {
        a = x % 10;
        if ((__INT_MAX__ / 10 > abs(output)) || ((__INT_MAX__ / 10 == abs(output)) && (__INT_MAX__ % 10 >= abs(a)))) {
            output = output * 10 + a;
            x /= 10;
        }
        else {
            return 0;
        }
    }
    return output;
}

int main() {
    long a;
    scanf("%ld", &a);
    int output = reverse(a);
    printf("%d", output);
    return 0;
}