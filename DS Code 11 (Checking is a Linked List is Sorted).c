//Checking is a Linked List is Sorted 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MIN

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p){
    while (p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");  // Newline for better readability
}

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int isSorted(struct Node *p){
    int x = INT_MIN;  // Use INT_MIN to represent the lowest possible integer value

    while (p != NULL){
        if (p->data < x)
            return 0;
  //  printf("Gýrýlen degerler artan sýra ýle ýlerledýgý ýcýn yanlýs bu yuzden :");
            
        x = p->data;
        p = p->next;
    }
   // printf("Gýrýlen degerler artan sýra ýle ýlerledýgý ýcýn dogur bu yuzden :");
    return 1;
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {5, 15, 06, 25, 35, 88};
    
	create(A, 5);
	
  //create(B, 6);
    

    Display(first);  // Display the list to verify its contents
    printf("%d\n", isSorted(first));  // Print whether the list is sorted

    return 0;
}

