#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;  // *first; yapýlabilir ya da mainde struct Node *first yaparak tanýmlnabilir

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
    // Fonksiyon 1: Önce düðümün verisini yazdýrýr, ardýndan sonraki düðüme geçer. Çýktý: Baþtan sona doðru sýralý.
    
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        RDisplay1(ptr->next);  // Doðru fonksiyon çaðrýsý
    }
}

void RDisplay2(struct Node *ptr) {  // RECURSIVE FUNCTION 2
    // Fonksiyon 2: Önce sonraki düðüme geçer, ardýndan dönüþte düðümün verisini yazdýrýr. Çýktý: Sondan baþa doðru ters sýralý.
    // Bunu stack gibi düþünebiliriz, sayýlarý depolar depolar daha sonra son giren ilk çýkar
    if (ptr != NULL) {  // Yanlýþ deðiþken ismi düzeltildi
        RDisplay2(ptr->next);  // Doðru fonksiyon çaðrýsý
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

