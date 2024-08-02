#include <stdio.h>
#include <stdlib.h>

// Node yapýsýný tanýmlama
struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Baðlý listeyi ekrana yazdýran fonksiyon
void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Yeni satýr eklemek daha iyi görsellik saðlar.
}

// Baðlý liste oluþturma fonksiyonu
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

// Ýki listeyi birleþtiren fonksiyon
void Concatenating(struct Node *p, struct Node *q) {
    third = p; // Üçüncü listeyi birinci listeyle baþlat

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = q; // Ýkinci listeyi birinci listenin sonuna ekle
}

// Ýki baðlý listeyi sýralayarak birleþtiren fonksiyon
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

    // Kalan elemanlarý ekle
    if (p) last->next = p;
    if (q) last->next = q;
}

int main() {
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};

    // Ýlk ve ikinci listeyi oluþtur
    create(&first, A, 5);
    create(&second, B, 5);

    // Listeleri birleþtir
    
    Concatenating(first, second); // Birbiri ardýna eklemek için bu fonksiyon kullanabilirsiniz.  !!!!!!!!!
    //Merge(first, second);  // Eðer sýralý birleþtirme istiyorsanýz bu satýrý kullanabilirsiniz. !!!!!!!!!

    // Sonucu göster
    printf("Concatenated Linked List: ");
    Display(third);

    return 0;
}

