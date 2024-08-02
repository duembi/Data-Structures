#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT32_MIN için eklenen kütüphane

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Baðlý liste oluþturma fonksiyonu
void create(int A[], int n) {
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

// Baðlý listeden maksimum deðeri bulan fonksiyon
int Max(struct Node *p) {
    int max = INT_MIN;

    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next; // Döngünün her adýmýnda sonraki düðüme geç
    }

    return max;
}


/*
int max(strucut node *p){ // FARKLI BIR DONGU ORNEGI
	
	int x = 0;
	
	if(p==0){
		
		return INT_MIN;
	}
	else{
		
		x = max(p->next);
		
		if(x > p->data){
			
			return x;
		}
		else{
			
			return p->data;
		}	
	}
}
*/



/*
int max(){ // RECURSIVE FUNCTION ORNEGI
	
	int x = 0;
	
	if(p==0){
		
		return INT_MIN;
	}
	
	x = max(p->next);
	
	
	
	return x > p->data ? x : p -> data;
}
*/

// Baðlý listeden maksimum deðeri bulan rekürsif fonksiyon
int RMax(struct Node *p) {
    int x = 0;

    if (p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2,88};
    create(A, 9);

    printf("Max %d\n", Max(first)); // Týrnak karakterleri düzeltildi

    return 0;
}

