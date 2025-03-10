#include <stdio.h>
#include <stdlib.h>

// Node yap�s�
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Listeyi olu�turma fonksiyonu
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

// Listeyi ekrana yazd�rma fonksiyonu
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Listedeki eleman say�s�n� bulma fonksiyonu
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

    // Ge�ersiz indeks kontrol�
    if (index < 0 || index > count(p)) return;

    // Yeni d���m i�in bellek ay�rma
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0) {  // Ba�tan ekleme
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
    create(A, 6); // Listeyi olu�turuyoruz

    Insert(first, 0, 15); // Ba�tan ekleme
    Insert(first, 0, 8);  // Ba�tan ekleme
    Insert(first, 0, 9);  // Ba�tan ekleme
    Insert(first, 1, 10); // Araya ekleme
    Display(first);       // Listeyi g�ster

    return 0;
}

