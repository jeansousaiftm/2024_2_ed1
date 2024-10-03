#include<stdio.h>

int main() {

    double a[10];

    //printf("%d\n", a);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", &a[i]);
    }

    return 0;
}
