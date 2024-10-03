#include<stdio.h>
#define PI 3.14159

void calcular(double r, double* a, double* v) {
    *a = 4 * PI * r * r;
    *v = (4 / 3.0) * PI * r * r * r;
}

int main() {

    double a, v;

    calcular(5, &a, &v);

    printf("%lf %lf\n", a, v);

    return 0;
}
