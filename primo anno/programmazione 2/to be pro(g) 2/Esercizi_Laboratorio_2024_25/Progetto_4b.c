#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   

// Definizione del nodo della lista
typedef struct listNode {
    char data;
    struct listNode* next;
} ListNode;

// Definizione della coda
typedef struct charQueue {
    ListNode* front;
    ListNode* rear;
    int size;
} *CharQueueADT;

// Crea una nuova coda vuota
CharQueueADT mkQueue(void) {
    CharQueueADT q = (CharQueueADT)malloc(sizeof(struct charQueue));
    if (q == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Distrugge la coda e libera la memoria
void dsQueue(CharQueueADT* pq) {
    if (pq == NULL || *pq == NULL) return;
    ListNode* current = (*pq)->front;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(*pq);
    *pq = NULL;
}

// Inserisce un elemento in coda
_Bool enqueue(CharQueueADT q, const char e) {
    if (q == NULL) return false;

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) return false;

    newNode->data = e;
    newNode->next = NULL;

    if (q->rear == NULL) { // Coda vuota
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
    return true;
}

// Rimuove il primo elemento dalla coda
_Bool dequeue(CharQueueADT q, char* res) {
    if (q == NULL || q->front == NULL) return false;

    ListNode* temp = q->front;
    if (res != NULL)
        *res = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return true;
}

// Controlla se la coda è vuota
_Bool isEmpty(CharQueueADT q) {
    return (q == NULL || q->size == 0);
}

// Ritorna la dimensione della coda
int size(CharQueueADT q) {
    if (q == NULL) return 0;
    return q->size;
}

// Guarda un elemento in posizione `position` senza rimuoverlo
_Bool peek(CharQueueADT q, int position, char* res) {
    if (q == NULL || position < 0 || position >= q->size) return false;

    ListNode* current = q->front;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    if (res != NULL)
        *res = current->data;
    return true;
}
