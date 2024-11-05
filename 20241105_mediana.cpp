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
    Node* mid;
    int c;

    List() { // O(1)
        first = NULL;
        last = NULL;
        mid = NULL;
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
            mid = n;
            return;
        }
        last->next = n;
        last = n;
        if (c % 2 == 1) {
            mid = mid->next;
        }
    }

    double calcMid() {
        if (empty()) return 0;
        if (c % 2 == 1) {
            return mid->value;
        }
        int v1 = mid->value;
        int v2 = mid->next->value;
        return (v1 + v2) / 2.0;
    }

    void print() { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("%.2lf\n", calcMid());
    }

    int size() { // O(1)
        return c;
    }

};

int main() {

    List l;

    int n, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);
        l.pushBack(x);
        l.print();
    }

    return 0;
}
