#include<stdio.h>

void divide(double a, int* i, int* f) {
    char tmp[100];
    sprintf(tmp, "%.6lf", a);
    sscanf(tmp, "%d.%d", i, f);
}

int main() {
    int i, d;
    divide(10.89, &i, &d);
    printf("%d %d\n", i, d);
    return 0;
}
