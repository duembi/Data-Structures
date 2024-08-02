// Doubly Linked List Code

#include <stdio.h>
#include <stdlib.h> // malloc için gerekli

// Ýki yönlü baðlý liste düðümü
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;

// Listeyi oluþturur
void Creat(int A[], int n) {
    struct node *t, *last;
    int i;

    if (n <= 0) return; // Boþ diziler için hiçbir þey yapma

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

// Listeyi ekrana yazdýrýr
void Display(struct node *p) {
    if (p == NULL) {
        printf("Liste boþ.\n");
        return;
    }

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Listenin uzunluðunu döndürür
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

    // Listeyi oluþtur
    Creat(A, 5);

    // Liste uzunluðunu ekrana yazdýr
    printf("Length is : %d\n", Length(first));

    // Listeyi ekrana yazdýr
    Display(first);

    return 0;
}

