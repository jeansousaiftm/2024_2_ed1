
#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() { // O(1)
        value = 0;
        next = NULL;
    }

    Node(int _value) { // O(1)
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* first;
    Node* last;
    int c;

    List() { // O(1)
        first = NULL;
        last = NULL;
        c = 0;
    }


    bool empty() { // O(1)
        return first == NULL;
    }

    void pushBack(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void printLower() { // O(n)
        Node* aux = first;
        int i = 0, lower = -1, lowerValue;
        while (aux != NULL) {
            if (lower == -1 || aux->value < lowerValue) {
                lowerValue = aux->value;
                lower = i;
            }
            aux = aux->next;
            i++;
        }
        printf("Menor valor: %d\n", lowerValue);
        printf("Posicao: %d\n", lower);
    }

};

int main() {

    List l;

    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.pushBack(x);
    }

    l.printLower();

    return 0;
}
