#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;  // *first; yap�labilir ya da mainde struct Node *first yaparak tan�mlnabilir

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {  // YUKARIDA firs -> data = A[0] zaten
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void RDisplay1(struct Node *ptr) {  // RECURSIVE FUNCTION 1
    // Fonksiyon 1: �nce d���m�n verisini yazd�r�r, ard�ndan sonraki d���me ge�er. ��kt�: Ba�tan sona do�ru s�ral�.
    
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        RDisplay1(ptr->next);  // Do�ru fonksiyon �a�r�s�
    }
}

void RDisplay2(struct Node *ptr) {  // RECURSIVE FUNCTION 2
    // Fonksiyon 2: �nce sonraki d���me ge�er, ard�ndan d�n��te d���m�n verisini yazd�r�r. ��kt�: Sondan ba�a do�ru ters s�ral�.
    // Bunu stack gibi d���nebiliriz, say�lar� depolar depolar daha sonra son giren ilk ��kar
    if (ptr != NULL) {  // Yanl�� de�i�ken ismi d�zeltildi
        RDisplay2(ptr->next);  // Do�ru fonksiyon �a�r�s�
        printf("%d ", ptr->data);
    }
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);

    printf("Forward Display: ");
    RDisplay1(first);
    printf("\n");

    printf("Reverse Display: ");
    RDisplay2(first);
    printf("\n");

    return 0;
}

