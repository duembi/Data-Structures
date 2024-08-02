#include<stdio.h>
#include<stdlib.h>

// �ki y�nl� ba�l� liste d���m�
struct node {
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;

// Listeyi olu�turur
void Create(int A[], int n) {
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

// Listeden bir eleman siler ve silinen eleman�n de�erini d�nd�r�r
int Delete(struct node *p, int index) {
    struct node *q;
    int i, x = -1;

    if (index < 1 || index > Length(p)) {
        return -1; // Ge�ersiz indeks kontrol�
    }

    if (index == 1) { // �lk d���m� silme i�lemi
        q = first; // �lk d���m� ge�ici de�i�kene ata
        x = q->data; // Silinen d���m�n verisini sakla
        first = first->next; // �lk d���m� g�ncelle

        if (first) {
            first->prev = NULL; // E�er liste bo� de�ilse, yeni ilk d���m�n prev i�aret�isini g�ncelle
        }
        free(q); // �lk d���m� bellekten serbest b�rak
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next; // �ndekse kadar ilerle
        }

        p->prev->next = p->next; // �nceki d���m�n next i�aret�isini g�ncelle

        if (p->next) {
            p->next->prev = p->prev; // Sonraki d���m varsa, onun prev i�aret�isini g�ncelle
        }

        x = p->data; // Silinen d���m�n verisini sakla
        free(p); // D���m� bellekten serbest b�rak
    }

    return x; // Silinen d���m�n verisini d�nd�r
}

int main() {
    int A[] = {10, 20, 30, 40, 50};

    // Listeyi olu�tur
    Create(A, 5);
	
	Display(first);
    // �lk eleman� sil
    int deletedValue = Delete(first, 1);
    if (deletedValue != -1) {
        printf("\nSilinen deger: %d\n", deletedValue);
    } else {
        printf("Ge�ersiz index.\n");
    }

    // Listeyi ekrana yazd�r
    Display(first);

    return 0;
}

