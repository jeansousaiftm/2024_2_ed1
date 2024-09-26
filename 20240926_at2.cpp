#include<stdio.h>
#define TAM 10

struct Funcionario {
    char nome[100], cargo[100];
    double base, beneficios, descontos;

    void ler() {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", cargo);
        scanf("%lf%*c", &base);
        scanf("%lf%*c", &beneficios);
        scanf("%lf%*c", &descontos);
    }

    void imprimir() {
        printf("%s\n", nome);
        printf("%s\n", cargo);
        printf("Base: R$%.2lf ", base);
        printf("Beneficios: R$%.2lf ", beneficios);
        printf("Descontos: R$%.2lf ", descontos);
        printf("Liquido: R$%.2lf\n", calculaSalarioLiquido());
    }

    double calculaSalarioLiquido() {
        return (base + beneficios) - descontos;
    }
};

struct Loja {

    Funcionario f[TAM];
    double total;
    double maior;
    int posMaior;
    int q;

    Loja() {
        q = 0;
        total = 0;
        maior = -99999999;
        posMaior = -1;
    }

    void ler() {
        if (q >= TAM) {
            printf("Cheia\n");
            return;
        }
        f[q].ler();
        double s = f[q].calculaSalarioLiquido();
        total += s;
        if (s > maior) {
            maior = s;
            posMaior = q;
        }
        q++;
    }

    void imprimir() {
        for (int i = 0; i < q; i++) {
            f[i].imprimir();
        }
    }

    void mediaSalarial() {
        if (q == 0) {
            printf("Vazia");
            return;
        }
        printf("R$%.2lf\n", total / q);
    }

    void mediaSalarialLoop() {
        if (q == 0) {
            printf("Vazia");
            return;
        }
        double media = 0;
        for (int i = 0; i < q; i++) {
            media += f[i].calculaSalarioLiquido();
        }
        printf("R$%.2lf\n", media / q);
    }

    void maiorSalario() {
        if (q == 0) {
            printf("Vazia\n");
            return;
        }
        f[posMaior].imprimir();
    }

    void maiorSalarioLoop() {
        if (q == 0) {
            printf("Vazia\n");
            return;
        }
        int m = f[0].calculaSalarioLiquido();
        int p = 0;
        for (int i = 1; i < q; i++) {
            double s = f[i].calculaSalarioLiquido();
            if (s > m) {
                m = s;
                p = i;
            }
        }
        f[p].imprimir();
    }

};

int main() {
    Loja l;
    int o;
    do {
        printf("1. Ler\n2. Listar\n3. Media\n4. Maior\n");
        scanf("%d%*c", &o);
        switch(o) {
        case 1:
            l.ler();
            break;
        case 2:
            l.imprimir();
            break;
        case 3:
            l.mediaSalarial();
            break;
        case 4:
            l.maiorSalario();
            break;
        }
    } while (o == 1 || o == 2 || o == 3 || o == 4);
    return 0;
}
