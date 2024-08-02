// Reverse a Linked List 


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// Listeyi ekrana yazdýran fonksiyon
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Sonuçlarýn daha okunabilir olmasý için
}

// Verilen bir dizi kullanarak baðlý liste oluþturan fonksiyon
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Liste içindeki düðüm sayýsýný hesaplayan yardýmcý fonksiyon
int count(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

// Listeyi geçici bir dizi kullanarak tersine çeviren fonksiyon
void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p)); // Bellek tahsisi

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

    free(A); // Bellek sýzýntýsýný önlemek için
}

// Listeyi iteratif olarak tersine çeviren fonksiyon
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Listeyi rekürsif (öz-yineli) olarak tersine çeviren fonksiyon
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    printf("Original List: ");
    Display(first);

    Reverse1(first); // Listeyi tersine çeviren fonksiyonlardan birini çaðýr
    printf("Reversed List using Reverse1: ");
    Display(first);

    // Listeyi yeniden oluþtur ve baþka yöntemlerle test et
    create(A, 5);
    Reverse2(first); // Listeyi tersine çeviren baþka bir fonksiyon
    printf("Reversed List using Reverse2: ");
    Display(first);

    // Listeyi yeniden oluþtur ve baþka yöntemlerle test et
    create(A, 5);
    Reverse3(NULL, first); // Listeyi tersine çeviren rekürsif fonksiyon
    printf("Reversed List using Reverse3: ");
    Display(first);

    return 0;
}

