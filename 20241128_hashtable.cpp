#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<list>
#define M 7
using namespace std;

struct HashTable {

    list<int> t[M];

    int hashCode(int value) { //O(1)
        return value % M;
    }

    void insert(int value) { //O(1) + complexidade p/ hashCode
        int h = hashCode(value);
        t[h].push_back(value);
    }

    bool find(int value) { //O(n / m) + complexidade p/ hashCode
        int h = hashCode(value);
        list<int>::iterator it;
        for (it = t[h].begin(); it != t[h].end(); it++) {
            if (value == *(it)) {
                return true;
            }
        }
        return false;
    }

    void remove(int value) { //O(n / m) + complexidade p/ hashCode
        int h = hashCode(value);
        t[h].remove(value);
    }

    void print() { //O(n)
        for (int i = 0; i < M; i++) {
            printf("[ %d (%d) ] -> ", i, t[i].size());
            list<int>::iterator it;
            for (it = t[i].begin(); it != t[i].end(); it++) {
                printf("%d -> ", *(it));
            }
            printf("\n");
        }

    }

};

int main() {

    srand(time(NULL));

    HashTable h;

    for (int i = 0; i < 1000; i++) {
        h.insert(rand() % 1000);
    }

    h.print();

    return 0;
}
