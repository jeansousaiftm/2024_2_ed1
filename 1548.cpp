

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

    void enqueueOrdered(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        if (value > first->value) {
            n->next = first;
            first = n;
            return;
        }
        if (value < last->value) {
            last->next = n;
            last = n;
            return;
        }
        Node *aux = first;
        while (aux->next->value > value) {
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
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

};

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] < v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}
/*
int main() {

    int n, m;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        int v[m];
        Queue q;
        for (int i = 0; i < m; i++) {
            scanf("%d", &v[i]);
            q.enqueue(v[i]);
        }
        bubbleSort(v, m);
        int r = 0;
        for (int i = 0; i < m; i++) {
            //printf("%d %d\n", q.front(), v[i]);
            if (q.front() == v[i]) {
                r++;
            }
            q.dequeue();
        }
        printf("%d\n", r);
    }

    return 0;
}
*/

int main() {

    int n, m, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        Queue q, qo;
        for (int i = 0; i < m; i++) {
            scanf("%d", &x);
            q.enqueue(x);
            qo.enqueueOrdered(x);
        }
        int r = 0;
        for (int i = 0; i < m; i++) {
            //printf("%d %d\n", q.front(), v[i]);
            if (q.front() == qo.front()) {
                r++;
            }
            q.dequeue();
            qo.dequeue();
        }
        printf("%d\n", r);
    }

    return 0;
}
