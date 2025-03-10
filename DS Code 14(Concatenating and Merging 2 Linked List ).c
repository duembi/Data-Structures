#include <stdio.h>
#include <stdlib.h>

// Node yap�s�n� tan�mlama
struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Ba�l� listeyi ekrana yazd�ran fonksiyon
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Yeni sat�r eklemek daha iyi g�rsellik sa�lar.
}

// Ba�l� liste olu�turma fonksiyonu
void create(struct Node **list, int A[], int n) {
    int i;
    struct Node *t, *last;
    *list = (struct Node *)malloc(sizeof(struct Node));
    (*list)->data = A[0];
    (*list)->next = NULL;
    last = *list;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// �ki listeyi birle�tiren fonksiyon
void Concatenating(struct Node *p, struct Node *q) {
    third = p; // ���nc� listeyi birinci listeyle ba�lat

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = q; // �kinci listeyi birinci listenin sonuna ekle
}

// �ki ba�l� listeyi s�ralayarak birle�tiren fonksiyon
void Merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    // Kalan elemanlar� ekle
    if (p) last->next = p;
    if (q) last->next = q;
}

int main() {
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};

    // �lk ve ikinci listeyi olu�tur
    create(&first, A, 5);
    create(&second, B, 5);

    // Listeleri birle�tir
    
    Concatenating(first, second); // Birbiri ard�na eklemek i�in bu fonksiyon kullanabilirsiniz.  !!!!!!!!!
    //Merge(first, second);  // E�er s�ral� birle�tirme istiyorsan�z bu sat�r� kullanabilirsiniz. !!!!!!!!!

    // Sonucu g�ster
    printf("Concatenated Linked List: ");
    Display(third);

    return 0;
}

