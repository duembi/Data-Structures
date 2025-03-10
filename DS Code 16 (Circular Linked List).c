#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
} * Head;

// Listeyi olu�turur
void create(int A[], int n){
    int i;
    struct Node *t, *last;

    // �lk d���m� olu�tur
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    // Di�er d���mleri olu�tur
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Listeyi g�sterir
void Display(struct Node *h){
    if (h == NULL) {
        printf("Liste bo�.\n");
        return;
    }

    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

// �zyinelemeli g�sterim
void RDisplay(struct Node *h){
    static int flag = 0;
    if (h != Head || flag == 0) {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

// Listenin uzunlu�unu d�nd�r�r
int Length(struct Node *p){
    int len = 0;
    if (p == NULL) {
        return len; // Bo� liste i�in 0 d�nd�r
    }
    do {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

// D���m ekler
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    int len = Length(p);
    if (index < 0 || index > len) {
        printf("Ge�ersiz index.\n");
        return;
    }

    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        } else {
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } else {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// D���m siler
int Delete(struct Node *p, int index){
    struct Node *q;
    int i, x;
    int len = Length(Head);

    if (index < 0 || index >= len) {
        printf("Ge�ersiz index.\n");
        return -1;
    }
    if (index == 0) {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (Head == p) {
            free(Head);
            Head = NULL;
        } else {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    } else {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

// Ana fonksiyon
int main(){
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    int deletedValue = Delete(Head, 8);
    if (deletedValue != -1) {
        printf("Silinen de�er: %d\n", deletedValue);
    }

    RDisplay(Head);
    printf("\n");

    Insert(Head, 3, 10);
    Display(Head);

    return 0;
}

