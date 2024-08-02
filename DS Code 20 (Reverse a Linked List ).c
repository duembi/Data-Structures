// Reverse a Linked List 


#include <stdio.h>
#include <stdlib.h>

// Baðlý liste düðümü
struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Listeyi ekrana yazdýrýr
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Baðlý liste oluþturur
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    
    // Ýlk düðümü oluþtur ve baþlat
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Diðer düðümleri oluþtur
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Liste uzunluðunu hesaplar
int count(struct Node *p) {
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Bir dizi kullanarak listeyi tersine çevirir
void Reverse1(struct Node *p) {
    int *A, i = 0;
    struct Node *q = p;

    // Bellek tahsisi
    A = (int *)malloc(sizeof(int) * count(p));

    // Listeyi diziye kopyala
    while (q != NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    // Diziyi kullanarak listeyi tersine çevir
    q = p;
    i--;
    while (q != NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }

    // Belleði serbest býrak
    free(A);
}

// Üç iþaretçi kullanarak listeyi tersine çevirir
void Reverse2(struct Node *p) {
    struct Node *q = NULL, *r = NULL;

    // Listeyi tersine çevir
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q; // Ýlk düðümü güncelle
}

// Özyinelemeli fonksiyon ile listeyi tersine çevirir
void Reverse3(struct Node *q, struct Node *p) {
    if (p != NULL) {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q; // Ýlk düðümü güncelle
    }
}

int main() {
    int A[] = {10, 20, 40, 50, 60};

    // Listeyi oluþtur
    create(A, 5);

    // Listeyi tersine çevir ve ekrana yazdýr
    Reverse1(first);
    printf("Reverse1 kullanilarak tersine cevrildi: ");
    Display(first);

    // Listeyi tekrar tersine çevir ve ekrana yazdýr
    Reverse2(first);
    printf("Reverse2 kullanilarak tersine cevrildi: ");
    Display(first);

    // Listeyi tekrar tersine çevir ve ekrana yazdýr
    Reverse3(NULL, first);
    printf("Reverse3 kullanilarak tersine cevrildi: ");
    Display(first);

    return 0;
}

