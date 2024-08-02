#include <stdio.h>
#include <stdlib.h>

// Linked List düðüm yapýsý
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Linked List oluþturma fonksiyonu
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

// Linked List'te sýraya göre arama ve ilk sýraya alma fonksiyonu
struct Node *LSearch(struct Node *p, int key) {
    struct Node *q = NULL; // Baþlangýçta q'yu NULL olarak ayarlayýn

    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) { // q NULL deðilse yani p ilk eleman deðilse
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

// Linked List'te rekürsif arama fonksiyonu
struct Node *RSearch(struct Node *p, int key) {
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

// Linked List'i yazdýrma fonksiyonu
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
    Display(first);  // Listenin baþlangýçtaki durumunu yazdýr

    temp = LSearch(first, 8);  // 8'i liste baþýna taþý ve arama iþlemi yap
    if (temp != NULL)
        printf("Aranan Deger: %d\n", temp->data);
    else
        printf("Deðer Bulunamadý\n");

    printf("Aramadan Sonra Linked List:\n");
    Display(first);  // Listeyi yeniden yazdýr

    return 0;
}

