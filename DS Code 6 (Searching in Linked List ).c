#include <stdio.h>
#include <stdlib.h>

// Linked List d���m yap�s�
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Linked List olu�turma fonksiyonu
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Linked List'te s�raya g�re arama ve ilk s�raya alma fonksiyonu
struct Node *LSearch(struct Node *p, int key) {
    struct Node *q = NULL; // Ba�lang��ta q'yu NULL olarak ayarlay�n

    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) { // q NULL de�ilse yani p ilk eleman de�ilse
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Linked List'te rek�rsif arama fonksiyonu
struct Node *RSearch(struct Node *p, int key) {
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

// Linked List'i yazd�rma fonksiyonu
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Ana fonksiyon
int main() {
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    printf("Initial Linked List:\n");
    Display(first);  // Listenin ba�lang��taki durumunu yazd�r

    temp = LSearch(first, 8);  // 8'i liste ba��na ta�� ve arama i�lemi yap
    if (temp != NULL)
        printf("Aranan Deger: %d\n", temp->data);
    else
        printf("De�er Bulunamad�\n");

    printf("Aramadan Sonra Linked List:\n");
    Display(first);  // Listeyi yeniden yazd�r

    return 0;
}

