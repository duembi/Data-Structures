#include <stdio.h>
#include <stdlib.h>

// Node yapýsý
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Listeyi oluþturma fonksiyonu
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

// Listeyi ekrana yazdýrma fonksiyonu
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Listedeki eleman sayýsýný bulma fonksiyonu
int count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// Listeye eleman ekleme fonksiyonu
void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    // Geçersiz indeks kontrolü
    if (index < 0 || index > count(p)) return;

    // Yeni düðüm için bellek ayýrma
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {  // Baþtan ekleme
        t->next = first;
        first = t;
    } else {  // Araya ekleme
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Ana fonksiyon
int main() {
    int A[] = {10, 20, 30, 40, 50, 1};
    create(A, 6); // Listeyi oluþturuyoruz

    Insert(first, 0, 15); // Baþtan ekleme
    Insert(first, 0, 8);  // Baþtan ekleme
    Insert(first, 0, 9);  // Baþtan ekleme
    Insert(first, 1, 10); // Araya ekleme
    Display(first);       // Listeyi göster

    return 0;
}

