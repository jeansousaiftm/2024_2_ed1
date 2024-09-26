#include<stdio.h>
#include<ctime>
#define TAM 50

struct Data {

    int dia, mes, ano;

    Data() {
    }

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

    void ler() {
        scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    }

    void imprimir() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        Data hoje(now->tm_mday,
                now->tm_mon + 1,
                now->tm_year + 1900);
        if (mes < hoje.mes || (mes == hoje.mes && dia <= hoje.dia)) {
            return hoje.ano - ano;
        } else {
            return (hoje.ano - ano) - 1;
        }
    }

};

struct Cliente {

    char nome[100];
    Data nascimento;
    char sexo;
    int idade;

    void ler() {
        scanf("%[^\n]%*c", nome);
        nascimento.ler();
        scanf("%c%*c", &sexo);
        idade = nascimento.calcularIdade();
    }

    void imprimir() {
        printf("%s\n", nome);
        nascimento.imprimir();
        printf("%c\n", sexo);
        printf("%d\n", idade);
    }

};

int main() {
    Cliente c[TAM];
    int p = 0, o;
    do {
        printf("1. Ler\n2. Listar\n");
        scanf("%d%*c", &o);
        switch(o) {
        case 1:
            if (p >= TAM) {
                printf("Cheio\n");
                break;
            }
            c[p++].ler();
            break;
        case 2:
            for (int i = 0; i < p; i++) {
                c[i].imprimir();
            }
            break;
        }
    } while (o == 1 || o == 2);
    return 0;
}
