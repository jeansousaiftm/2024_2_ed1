
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

    void pushFront(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void print() { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    void generateFibonacci(int n) { //O(n)
        if (n == 1) {
            pushFront(1);
            return;
        }
        pushFront(1);
        pushFront(1);
        for (int i = 3; i <= n; i++) {
            int n1 = first->value;
            int n2 = first->next->value;
            pushFront(n1 + n2);
        }
    }

};

int main() {

    List l;

    int n;
    scanf("%d", &n);
    l.generateFibonacci(n);
    l.print();

    return 0;
}
