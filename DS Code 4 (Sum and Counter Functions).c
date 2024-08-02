#include <stdio.h>
#include <stdlib.h>

struct Node { // Define the structure for a Node

    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) { // Function to create a linked list from an array

    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}



/* // SAMPLE COUNTER FUNCTION !!!
int count(struct Node *p) { // Function to count the number of nodes in the list

    int counter = 0;
    while (p != 0) {
        counter++;
        p = p -> next;
    }
    return l;
}
*/

int count(struct Node *p) { // Function to count the number of nodes in the list

    int counter = 0;
    while (p) {
        counter++;
        p = p -> next;
    }
    return l;
}



/* // SAMPLE Recursive COUNTER Function  !!!!
int Rcount(struct Node *p) { // Recursive function to count the number of nodes in the list

    if (p == 0)
        return 0;
    else
        return Rcount(p -> next) + 1;;
}
*/


/* // SAMPLE Recursive COUNTER Function2 !!!
int Rcount(struct Node *p) { // Recursive function to count the number of nodes in the list
	
	int x;
	x = 0;
	
    if (p){
    
        x = Rcount(p -> next);
        
        return x+1;

	}
    else
        return x;
}
*/

int Rcount(struct Node *p) { // Recursive function to count the number of nodes in the list

    if (p != NULL)
        return Rcount(p -> next) + 1;
    else
        return 0;
}




/* // SAMPLE SUM FUNCTION
int add(struct Node *p) { // Function to sum the values of all nodes in the list

    int sum = 0;

    while (p) {
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}
*/

int add(struct Node *p) { // Function to sum the values of all nodes in the list

    int sum = 0;

    while (p != NULL) {
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}

int Radd(struct Node *p) { // Recursive function to sum the values of all nodes in the list

    if (p == NULL) // (P == 0)
        return 0;
    else
        return Radd(p -> next) + p -> data;
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    printf("Count: %d\n", count(first));
    printf("Recursive Count: %d\n", Rcount(first));

    printf("Sum: %d\n", sum(first));
    printf("Recursive Sum: %d\n", Rsum(first));

    struct Node *temp;    // Free the allocated memory

    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }

    return 0;
}

