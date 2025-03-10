// Reverse a Linked List 


#include <stdio.h>
#include <stdlib.h>

// Ba�l� liste d���m�
struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Listeyi ekrana yazd�r�r
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Ba�l� liste olu�turur
void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    
    // �lk d���m� olu�tur ve ba�lat
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Di�er d���mleri olu�tur
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Liste uzunlu�unu hesaplar
int count(struct Node *p) {
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// Bir dizi kullanarak listeyi tersine �evirir
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

    // Diziyi kullanarak listeyi tersine �evir
    q = p;
    i--;
    while (q != NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }

    // Belle�i serbest b�rak
    free(A);
}

// �� i�aret�i kullanarak listeyi tersine �evirir
void Reverse2(struct Node *p) {
    struct Node *q = NULL, *r = NULL;

    // Listeyi tersine �evir
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q; // �lk d���m� g�ncelle
}

// �zyinelemeli fonksiyon ile listeyi tersine �evirir
void Reverse3(struct Node *q, struct Node *p) {
    if (p != NULL) {
        Reverse3(p, p->next);
        p->next = q;
    } else {
        first = q; // �lk d���m� g�ncelle
    }
}

int main() {
    int A[] = {10, 20, 40, 50, 60};

    // Listeyi olu�tur
    create(A, 5);

    // Listeyi tersine �evir ve ekrana yazd�r
    Reverse1(first);
    printf("Reverse1 kullanilarak tersine cevrildi: ");
    Display(first);

    // Listeyi tekrar tersine �evir ve ekrana yazd�r
    Reverse2(first);
    printf("Reverse2 kullanilarak tersine cevrildi: ");
    Display(first);

    // Listeyi tekrar tersine �evir ve ekrana yazd�r
    Reverse3(NULL, first);
    printf("Reverse3 kullanilarak tersine cevrildi: ");
    Display(first);

    return 0;
}

