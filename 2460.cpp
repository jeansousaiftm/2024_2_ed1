#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() {
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct Queue {

    Node* first;
    Node* last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void dequeue() {
        if (empty()) return;
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
    }

    int front() {
        if (empty()) {
            printf("Empty queue\n");
            return -1;
        }
        return first->value;
    }

    void remove(int value) {
        if (empty()) return;
        if (first->value == value) {
            dequeue();
            return;
        }
        Node *aux = first;
        while (aux->next != NULL && aux->next->value != value) {
            aux = aux->next;
        }
        if (aux->next == NULL) return;
        if (aux->next == last) {
            Node *toDel = aux->next;
            aux->next = NULL;
            last = aux;
            delete(toDel);
            return;
        }
        Node *toDel = aux->next;
        aux->next = toDel->next;
        delete(toDel);
    }

};

/*
int main() {

    Queue q;

    int n, m, x;
    int v[100001];

    for (int i = 0; i <= 100000; i++) v[i] = 0;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);
        q.enqueue(x);
    }

    scanf("%d", &m);

    while (m--) {
        scanf("%d", &x);
        v[x] = 1;
    }

    x = 0;
    while (!q.empty()) {
        if (v[q.front()] == 0) {
            if (x > 0) printf(" ");
            printf("%d", q.front());
            x++;
        }
        q.dequeue();
    }

    printf("\n");
    return 0;
}
*/

int main() {

    Queue q;

    int n, m, x;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &x);
        q.enqueue(x);
    }

    scanf("%d", &m);

    while (m--) {
        scanf("%d", &x);
        q.remove(x);
    }

    x = 0;
    while (!q.empty()) {
        if (x > 0) printf(" ");
        printf("%d", q.front());
        x++;
        q.dequeue();
    }

    printf("\n");
    return 0;
}
