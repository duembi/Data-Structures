// Doubly Linked List Code

#include <stdio.h>
#include <stdlib.h> // malloc i�in gerekli

// �ki y�nl� ba�l� liste d���m�
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;

// Listeyi olu�turur
void Creat(int A[], int n) {
    struct node *t, *last;
    int i;

    if (n <= 0) return; // Bo� diziler i�in hi�bir �ey yapma

    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Listeyi ekrana yazd�r�r
void Display(struct node *p) {
    if (p == NULL) {
        printf("Liste bo�.\n");
        return;
    }

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Listenin uzunlu�unu d�nd�r�r
int Length(struct node *p) {
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

// Ana fonksiyon
int main() {
    int A[] = {10, 20, 30, 40, 50};

    // Listeyi olu�tur
    Creat(A, 5);

    // Liste uzunlu�unu ekrana yazd�r
    printf("Length is : %d\n", Length(first));

    // Listeyi ekrana yazd�r
    Display(first);

    return 0;
}

