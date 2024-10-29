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
        if (value <= 0) value = 1;
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

    void print() { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        int i = 0;
        while (aux != NULL) {
            printf("X[%d] = %d\n", i++, aux->value);
            aux = aux->next;
        }
    }

};

int main() {

    List l;

    for (int i = 0; i < 10; i++) {
        int x;
        scanf("%d", &x);
        l.pushBack(x);
    }

    l.print();

    return 0;
}
