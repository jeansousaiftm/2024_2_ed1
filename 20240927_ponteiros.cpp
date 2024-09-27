#include<stdio.h>

void calcular(int a, int b, int *soma, int *mult) {
    *soma = a + b;
    *mult = a * b;
}

int main() {

    int a, b, soma, mult;

    scanf("%d %d", &a, &b);

    calcular(a, b, &soma, &mult);

    printf("%d %d\n", soma, mult);

    return 0;
}
