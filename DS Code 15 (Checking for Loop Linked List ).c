// Checking for Loop Linked List 

#include <stdio.h>
#include <stdlib.h>

// Node yap�s�n� tan�mlama
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Ba�l� listeyi ekrana yazd�ran fonksiyon
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Yeni sat�r eklemek daha iyi g�rsellik sa�lar.
}

// Ba�l� liste olu�turma fonksiyonu
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

// Ba�l� listede d�ng� kontrol� yapan fonksiyon
int isLoop(struct Node *f) {
    struct Node *p, *q;
    p = q = f;

    do {
        p = p->next;
        q = (q && q->next) ? q->next->next : NULL; // q i�in g�venli eri�im kontrol�

    } while (p && q && p != q);

    return (p == q) ? 1 : 0; // p ve q'nun e�itli�i kontrol�
}

int main() {
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    
    // Ba�l� listeyi olu�tur
    create(A, 5);

    // D�ng� olu�tur
    t1 = first->next->next; // 30'u i�aret eder
    t2 = first->next->next->next->next; // 50'yi i�aret eder
    t2->next = t1; // D�ng� olu�tur: 50 -> 30

    // D�ng� kontrol�n� g�ster
    if (isLoop(first)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop in the linked list.\n");
    }

    return 0;
}


