#include<stdio.h>
#include<stdlib.h>

// Ýki yönlü baðlý liste düðümü
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;

// Listeyi oluþturur
void Create(int A[], int n) {
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

// Listeden bir eleman siler ve silinen elemanýn deðerini döndürür
int Delete(struct node *p, int index) {
    struct node *q;
    int i, x = -1;

    if (index < 1 || index > Length(p)) {
        return -1; // Geçersiz indeks kontrolü
    }

    if (index == 1) { // Ýlk düðümü silme iþlemi
        q = first; // Ýlk düðümü geçici deðiþkene ata
        x = q->data; // Silinen düðümün verisini sakla
        first = first->next; // Ýlk düðümü güncelle

        if (first) {
            first->prev = NULL; // Eðer liste boþ deðilse, yeni ilk düðümün prev iþaretçisini güncelle
        }
        free(q); // Ýlk düðümü bellekten serbest býrak
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next; // Ýndekse kadar ilerle
        }

        p->prev->next = p->next; // Önceki düðümün next iþaretçisini güncelle

        if (p->next) {
            p->next->prev = p->prev; // Sonraki düðüm varsa, onun prev iþaretçisini güncelle
        }

        x = p->data; // Silinen düðümün verisini sakla
        free(p); // Düðümü bellekten serbest býrak
    }

    return x; // Silinen düðümün verisini döndür
}

int main() {
    int A[] = {10, 20, 30, 40, 50};

    // Listeyi oluþtur
    Create(A, 5);
	
	Display(first);
    // Ýlk elemaný sil
    int deletedValue = Delete(first, 1);
    if (deletedValue != -1) {
        printf("\nSilinen deger: %d\n", deletedValue);
    } else {
        printf("Geçersiz index.\n");
    }

    // Listeyi ekrana yazdýr
    Display(first);

    return 0;
}

