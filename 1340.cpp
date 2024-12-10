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

struct Stack {

    Node* t;

    Stack() {
        t = NULL;
    }

    bool empty() { // O(1)
        return t == NULL;
    }

    void push(int value) { // O(1)
        Node* n = new Node(value);
        if (empty()) {
            t = n;
            return;
        }
        n->next = t;
        t = n;
    }

    void pop() { // O(1)
        if (empty()) {
            return;
        }
        if (t->next == NULL) {
            delete(t);
            t = NULL;
            return;
        }
        Node* toDel = t;
        t = t->next;
        delete(toDel);
    }

    int top() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return t->value;
    }

};

int main() {
    int n, a, b;

    while (scanf("%d", &n) != EOF) {

        Stack s;
        Queue q;
        Queue qo;

        bool canBeStack = true;
        bool canBeQueue = true;
        bool canBePriorityQueue = true;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if (a == 1) {
                s.push(b);
                q.enqueue(b);
                qo.enqueueOrdered(b);
            }
            if (a == 2) {
                if (s.top() != b) {
                    canBeStack = false;
                }
                if (q.front() != b) {
                    canBeQueue = false;
                }
                if (qo.front() != b) {
                    canBePriorityQueue = false;
                }
                s.pop();
                q.dequeue();
                qo.dequeue();
            }
        }

        if (canBeStack && !canBeQueue && !canBePriorityQueue) {
            printf("stack\n");
        } else if (canBeQueue && !canBeStack && !canBePriorityQueue) {
            printf("queue\n");
        } else if (canBePriorityQueue && !canBeStack && !canBeQueue) {
            printf("priority queue\n");
        } else if (!canBePriorityQueue && !canBeStack && !canBeQueue) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }

    }

}
