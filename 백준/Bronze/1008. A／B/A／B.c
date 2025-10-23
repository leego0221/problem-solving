#include <stdio.h>

int main(void) {
    double a, b, result;
    scanf("%lf %lf", &a, &b);
    result = a / b;
    printf("%.9lf", result);
    return 0;
}