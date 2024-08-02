// Doubly Linked List Code


#include <stdio.h>
#include <stdlib.h>

// Ýki yönlü baðlý liste düðümü
struct Node {
    int data; // Düðümün verisi
    struct Node *prev; // Önceki düðüme iþaretçi
    struct Node *next; // Sonraki düðüme iþaretçi
} *head = NULL; // Listenin baþý (head)

// Baðlý listeyi oluþturma fonksiyonu
void create(int A[], int n) {
    struct Node *t, *last;
    int i;

    if (n <= 0) return; // Boþ diziler için çýk

    // Ýlk düðümü oluþtur ve baþlat
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    // Dizinin diðer elemanlarý için düðümler oluþtur
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Listeyi ekrana yazdýrma fonksiyonu
void display(struct Node *p) {
    if (p == NULL) {
        printf("Liste boþ.\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Liste uzunluðunu hesaplayan fonksiyon
int length(struct Node *p) {
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Belirtilen konuma düðüm ekleyen fonksiyon
void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > length(p)) {
        printf("Geçersiz index.\n");
        return;
    }

    struct Node *t;
    int i;

    // Yeni düðüm oluþtur
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    // Baþa ekleme
    if (index == 0) {
        t->prev = NULL;
        t->next = head;
        if (head != NULL)
            head->prev = t;
        head = t;
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }

