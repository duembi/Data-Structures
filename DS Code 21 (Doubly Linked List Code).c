// Doubly Linked List Code


#include <stdio.h>
#include <stdlib.h>

// �ki y�nl� ba�l� liste d���m�
struct Node {
    int data; // D���m�n verisi
    struct Node *prev; // �nceki d���me i�aret�i
    struct Node *next; // Sonraki d���me i�aret�i
} *head = NULL; // Listenin ba�� (head)

// Ba�l� listeyi olu�turma fonksiyonu
void create(int A[], int n) {
    struct Node *t, *last;
    int i;

    if (n <= 0) return; // Bo� diziler i�in ��k

    // �lk d���m� olu�tur ve ba�lat
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    // Dizinin di�er elemanlar� i�in d���mler olu�tur
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Listeyi ekrana yazd�rma fonksiyonu
void display(struct Node *p) {
    if (p == NULL) {
        printf("Liste bo�.\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Liste uzunlu�unu hesaplayan fonksiyon
int length(struct Node *p) {
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Belirtilen konuma d���m ekleyen fonksiyon
void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > length(p)) {
        printf("Ge�ersiz index.\n");
        return;
    }

    struct Node *t;
    int i;

    // Yeni d���m olu�tur
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    // Ba�a ekleme
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

