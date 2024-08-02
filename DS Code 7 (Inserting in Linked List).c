#include <stdio.h>
#include <stdlib.h>

// Linked list düðüm yapýsý
struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Dizi kullanarak linked list oluþturma
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    if (first == NULL) {
        printf("Bellek tahsisi baþarýsýz oldu.\n");
        return;
    }
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        if (t == NULL) {
            printf("Bellek tahsisi baþarýsýz oldu.\n");
            return;
        }
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Linked listi yazdýrma
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Çýktýyý düzenlemek için yeni satýr
}

// Linked list'teki düðüm sayýsýný döndüren fonksiyon
int count(struct Node *p) {
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

// Belirli bir index'e düðüm ekleme
void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;

    if (index < 0 || index > count(p)) {
        printf("Gecersiz indeks: %d\n", index);
        return;
    }

    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Bellek tahsisi baþarýsýz oldu.\n");
        return;
    }
    t->data = x;

    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// Ana fonksiyon
int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    printf("Baslangic linked listi:\n");
    Display(first);

    // Yeni düðüm ekleme
    Insert(first, 0, 5); // Baþlangýçta 5 ekleme
    printf("Eklemeden sonra linked list:\n");
    Display(first);

    Insert(first, 3, 25); // 3. indise 25 ekleme
    printf("Eklemeden sonra linked list:\n");
    Display(first);

    Insert(first, 7, 60); // Sonuna 60 ekleme
    printf("Eklemeden sonra linked list:\n");
    Display(first);

    // Geçersiz indeks örneði
    Insert(first, 10, 70); // Geçersiz indeks
    return 0;
}

