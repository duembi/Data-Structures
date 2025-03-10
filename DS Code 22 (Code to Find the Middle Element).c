// Code to Find the Middle Element

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ba�l� liste d���m yap�s�
struct Node {
    int data;
    struct Node* next;
};

// Ba�l� listenin ba��n� temsil eden global bir i�aret�i
struct Node* head = NULL;

// Ba�l� listeyi olu�turma fonksiyonu
void create(int A[], int n) {
    struct Node* temp;
    struct Node* tail;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (int i = 1; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

// Orta eleman� bulma: Y�ntem 1
void middleNode1(struct Node* p) {
    int length = 0;
    struct Node* current = p;
    while (current) {
        length++;
        current = current->next;
    }

    int index = (int)ceil(length / 2.0);
    struct Node* q = head;
    for (int i = 0; i < index - 1; i++) {
        q = q->next;
    }
    printf("Middle Element (Method-I): %d\n", q->data);
}

// Orta eleman� bulma: Y�ntem 2
void middleNode2(struct Node* p) {
    struct Node* q = p;
    while (q && q->next) { // q ve q->next var m� kontrol et
        q = q->next->next;
        p = p->next;
    }
    printf("Middle Element (Method-II): %d\n", p->data);
}

// Orta eleman� bulma: Y�ntem 3
void middleNode3(struct Node* p) {
    struct Node* stack[100];  // Sabit boyutlu bir dizi olarak y���t
    int top = -1;  // Y���t�n ba�lang�� de�eri
    int length = 0;

    while (p) {
        stack[++top] = p;
        p = p->next;
    }

    length = top + 1;
    int popLength = (int)(floor(length / 2.0));

    while (popLength) {
        --top;
        popLength--;
    }

    printf("Middle Element (Method-III): %d\n", stack[top]->data);
}

// Belle�i serbest b�rakma fonksiyonu
void freeMemory(struct Node* head) {
    struct Node* current = head;
    while (current) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int n = sizeof(A) / sizeof(A[0]);

    create(A, n);

    printf("\n");
    middleNode1(head);
    middleNode2(head);
    middleNode3(head);

    freeMemory(head); // Belle�i serbest b�rak
    return 0;
}

