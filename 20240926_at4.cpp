#include<stdio.h>
#define TAM 20

struct Conjunto {

    int n;
    int v[TAM];

    Conjunto() {
        n = 0;
    }

    void ler() {
        scanf("%d", &n);
        if (n > TAM) {
            n = 0;
            printf("Tamanho maximo %d\n", TAM);
            return;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
    }

    void imprimir() {
        printf("[");
        for (int i = 0; i < n; i++) {
            printf("%d,", v[i]);
        }
        printf("]\n");
    }

    void uniao(Conjunto c2) {
        if (n + c2.n > TAM) {
            printf("Tamanho maximo %d\n", TAM);
            return;
        }
        for (int i = n, j = 0; j < c2.n; i++, j++) {
            v[i] = c2.v[j];
        }
        n += c2.n;
    }

    void intersecao(Conjunto c2) {
        int x = 0;
        int vi[TAM];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c2.n; j++) {
                if (v[i] == c2.v[j]) {
                    vi[x++] = v[i];
                    break;
                }
            }
        }
        n = x;
        for (int i = 0; i < x; i++) {
            v[i] = vi[i];
        }
    }

};

int main() {
    Conjunto c;
    c.ler();
    c.imprimir();
    Conjunto c2;
    c2.ler();
    c2.imprimir();
    c.intersecao(c2);
    c.imprimir();
    return 0;
}
