#include<stdio.h>
#include<string.h>

struct Node {

    char value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(char _value) {
        value = _value;
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

    void push(char value) { // O(1)
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

    char tmp[10001];

    int n;
    scanf("%d", &n);

    while (n--) {

        scanf("%s", tmp);

        Stack s;
        int q = 0;

        for (int i = 0; i < strlen(tmp); i++) {
            if (tmp[i] == '<') {
                s.push('<');
                continue;
            }
            if (tmp[i] == '>') {
                if (!s.empty()) {
                    q++;
                    s.pop();
                }
            }
        }

        printf("%d\n", q);

    }

    return 0;
}
