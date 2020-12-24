#include <stdio.h>
int mod = 10;

int f(int);

int main() {
    int acc = 0;
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        acc += f(i);
        acc = acc % mod;
    }
    printf("Result is %d", acc);
    return 0;
}

int f(int n) {
    int acc = 1;
    for(int i = 1; i <= n; ++i) {
        acc *= 2;
    }
    return acc;
}