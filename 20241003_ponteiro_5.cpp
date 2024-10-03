#include<stdio.h>

void vetor(int v[], int n, int* menor, int *maior) {
    *menor = v[0];
    *maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > *maior) *maior = v[i];
        if (v[i] < *menor) *menor = v[i];
    }
}

int main() {
    int maior, menor;

    int v[] = {3, 5, 2, 1, 6};

    vetor(v, 5, &menor, &maior);

    printf("%d %d\n", menor, maior);

    return 0;
}
