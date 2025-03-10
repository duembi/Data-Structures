// Reverse a Linked List 


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// Listeyi ekrana yazd�ran fonksiyon
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n"); // Sonu�lar�n daha okunabilir olmas� i�in
}

// Verilen bir dizi kullanarak ba�l� liste olu�turan fonksiyon
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

// Liste i�indeki d���m say�s�n� hesaplayan yard�mc� fonksiyon
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

// Listeyi ge�ici bir dizi kullanarak tersine �eviren fonksiyon
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

    free(A); // Bellek s�z�nt�s�n� �nlemek i�in
}

// Listeyi iteratif olarak tersine �eviren fonksiyon
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

// Listeyi rek�rsif (�z-yineli) olarak tersine �eviren fonksiyon
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

    Reverse1(first); // Listeyi tersine �eviren fonksiyonlardan birini �a��r
    printf("Reversed List using Reverse1: ");
    Display(first);

    // Listeyi yeniden olu�tur ve ba�ka y�ntemlerle test et
    create(A, 5);
    Reverse2(first); // Listeyi tersine �eviren ba�ka bir fonksiyon
    printf("Reversed List using Reverse2: ");
    Display(first);

    // Listeyi yeniden olu�tur ve ba�ka y�ntemlerle test et
    create(A, 5);
    Reverse3(NULL, first); // Listeyi tersine �eviren rek�rsif fonksiyon
    printf("Reversed List using Reverse3: ");
    Display(first);

    return 0;
}

