//Remove Duplicates Value from Linked List 


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");  // Newline for better readability
}

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
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q, *temp;

    while (p != NULL && p->next != NULL)
    {
        q = p->next;
        while (q != NULL && q->data == p->data)
        {
            temp = q;
            q = q->next;
            free(temp);
        }
        p->next = q;
        p = p->next;
    }
}

int main()
{
    int A[] = {10, 20, 20, 40, 50, 50, 50, 60};
    create(A, 8);

    RemoveDuplicate(first);
    Display(first);

    return 0;
}

