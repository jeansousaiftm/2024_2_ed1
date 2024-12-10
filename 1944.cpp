
#include<stdio.h>
#define N 500

struct Stack {

    char v[N];
    int t;

    Stack() {
        t = 0;
    }

    bool empty() { // O(1)
        return t == 0;
    }

    bool full() { // O(1)
        return t >= N;
    }

    void push(char value) { // O(1)
        if (full()) {
            printf("Full\n");
            return;
        }
        v[t++] = value;
    }

    void pop() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return;
        }
        t--;
    }

    int top() { // O(1)
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return v[t - 1];
    }

    void start() {
        if (empty()) {
            push('F');
            push('A');
            push('C');
            push('E');
        }
    }

    bool match(char c1, char c2, char c3, char c4) {
        return (c1 == v[t - 1]
                && c2 == v[t - 2]
                && c3 == v[t - 3]
                && c4 == v[t - 4]);
    }

};

int main() {
    Stack s;

    int n, r = 0;
    scanf("%d%*c", &n);

    while (n--) {
        s.start();
        char c1, c2, c3, c4;
        scanf("%c %c %c %c%*c", &c1, &c2, &c3, &c4);
        if (s.match(c1, c2, c3, c4)) {
            r++;
            s.pop();
            s.pop();
            s.pop();
            s.pop();
        } else {
            s.push(c1);
            s.push(c2);
            s.push(c3);
            s.push(c4);
        }
    }

    printf("%d\n", r);

    return 0;
}
