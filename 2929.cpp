#include<stdio.h>
#include<string.h>

struct Node {

    int value, minValue;
    Node* next;

    Node() {
        value = 0;
        minValue = 0;
        next = NULL;
    }

    Node(int _value, int _min) {
        value = _value;
        minValue = _min;
        next = NULL;
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
        if (empty()) {
            Node* n = new Node(value, value);
            t = n;
            return;
        }
        int minValue = t->minValue;
        if (value < minValue) minValue = value;
        Node* n = new Node(value, minValue);
        n->next = t;
        t = n;
    }

    void pop() { // O(1)
        if (empty()) {
            printf("EMPTY\n");
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

    void top() { // O(1)
        if (empty()) {
            printf("EMPTY\n");
            return;
        }
        printf("%d\n", t->minValue);
    }

};

int main() {

    int n;
    scanf("%d", &n);
    Stack s;

    for (int i = 0; i < n; i++) {
        char tmp[100];
        scanf("%s", tmp);
        if (strcmp(tmp, "PUSH") == 0) {
            int x;
            scanf("%d", &x);
            s.push(x);
        }
        if (strcmp(tmp, "POP") == 0) {
            s.pop();
        }
        if (strcmp(tmp, "MIN") == 0) {
            s.top();
        }
    }

    return 0;
}
