#include<stdio.h>
#define TAM 10

struct Livro {
    char titulo[100], autor[100];
    int numPaginas;

    void ler() {
        scanf("%[^\n]%*c", titulo);
        scanf("%[^\n]%*c", autor);
        scanf("%d%*c", &numPaginas);
    }

    void imprimir() {
        printf("%s\n", titulo);
        printf("%s\n", autor);
        printf("%d\n", numPaginas);
    }

};

struct Biblioteca {

    Livro l[TAM];
    int maior;
    int posMaior;
    int q;

    Biblioteca() {
        q = 0;
        maior = -99999999;
        posMaior = -1;
    }

    void ler() {
        if (q >= TAM) {
            printf("Cheia\n");
            return;
        }
        l[q].ler();
        if (l[q].numPaginas > maior) {
            maior = l[q].numPaginas;
            posMaior = q;
        }
        q++;
    }

    void imprimir() {
        for (int i = 0; i < q; i++) {
            l[i].imprimir();
        }
    }

    void maiorNumPaginas() {
        if (q == 0) {
            printf("Vazia\n");
            return;
        }
        l[posMaior].imprimir();
    }

    void maiorNumPaginasLoop() {
        if (q == 0) {
            printf("Vazia\n");
            return;
        }
        int m = l[0].numPaginas;
        int p = 0;
        for (int i = 1; i < q; i++) {
            if (l[0].numPaginas > m) {
                m = l[0].numPaginas;
                p = i;
            }
        }
        l[p].imprimir();
    }

};

int main() {
    Biblioteca b;
    int o;
    do {
        printf("1. Ler\n2. Listar\n3. Maior\n");
        scanf("%d%*c", &o);
        switch(o) {
        case 1:
            b.ler();
            break;
        case 2:
            b.imprimir();
            break;
        case 3:
            b.maiorNumPaginas();
            break;
        }
    } while (o == 1 || o == 2 || o == 3);
    return 0;
}
