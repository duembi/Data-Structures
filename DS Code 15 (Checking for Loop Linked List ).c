// Checking for Loop Linked List 

#include <stdio.h>
#include <stdlib.h>

// Node yapýsýný tanýmlama
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Baðlý listeyi ekrana yazdýran fonksiyon
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Yeni satýr eklemek daha iyi görsellik saðlar.
}

// Baðlý liste oluþturma fonksiyonu
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

// Baðlý listede döngü kontrolü yapan fonksiyon
int isLoop(struct Node *f) {
    struct Node *p, *q;
    p = q = f;

    do {
        p = p->next;
        q = (q && q->next) ? q->next->next : NULL; // q için güvenli eriþim kontrolü

    } while (p && q && p != q);

    return (p == q) ? 1 : 0; // p ve q'nun eþitliði kontrolü
}

int main() {
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    
    // Baðlý listeyi oluþtur
    create(A, 5);

    // Döngü oluþtur
    t1 = first->next->next; // 30'u iþaret eder
    t2 = first->next->next->next->next; // 50'yi iþaret eder
    t2->next = t1; // Döngü oluþtur: 50 -> 30

    // Döngü kontrolünü göster
    if (isLoop(first)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop in the linked list.\n");
    }

    return 0;
}


