#include<stdio.h>
#include<string.h>

struct Node {

    char language[100];
    char translation[100];
    Node* next;

    Node() { // O(1)
        strcpy(language, "");
        strcpy(translation, "");
        next = NULL;
    }

    Node(char _language[], char _translation[]) { // O(1)
        strcpy(language, _language);
        strcpy(translation, _translation);
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

    void pushBack(char language[], char translation[]) { // O(1)
        Node *n = new Node(language, translation);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void printTranslation(char language[]) { //O(n)
        Node* aux = first;
        while (aux != NULL) {
            if (strcmp(aux->language, language) == 0) {
                printf("%s\n", aux->translation);
                return;
            }
            aux = aux->next;
        }
    }

};

int main() {

    List l;
    int n, m;
    char language[100], translation[100], name[100];

    scanf("%d%*c", &n);

    for (int i = 0; i < n; i++) {
        scanf("%[^\n]%*c", language);
        scanf("%[^\n]%*c", translation);
        l.pushBack(language, translation);
    }

    scanf("%d%*c", &m); // O (n * m)

    for (int i = 0; i < m; i++) {
        scanf("%[^\n]%*c", name);
        scanf("%[^\n]%*c", language);

        printf("%s\n", name);
        l.printTranslation(language);
        printf("\n");
    }

    return 0;
}
