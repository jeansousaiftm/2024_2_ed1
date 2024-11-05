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

    int size() { // O(1)
        return c;
    }

    int books(int n) {
        if (n <= 0) return 0;
        int b = 1;
        Node *aux = first;
        while (aux != NULL && n > 0) {
            n -= aux->value;
            b++;
            aux = aux->next;
        }
        if (aux == NULL && n >= 0) return 0;
        if (n == 0) return b;
        return b - 1;
    }

};

int main() {

    List l;
    int n, x;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);
        l.pushBack(x);
    }

    scanf("%d", &n);
    printf("%d\n", l.books(n));

    return 0;
}

