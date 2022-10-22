#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter N: ");
    int n;
    scanf("%d", &n);

    int res = (int) pow(2,n+1) - 2;
    printf("Result is %d", res);

    return 0;
}

