#include "charQueueADT.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 8

struct charQueue {
    int capacity;
    char* a;
    int size;
    int rear;
    int front;
};

CharQueueADT mkQueue() {
    CharQueueADT q = (CharQueueADT)malloc(sizeof(struct charQueue));
    
    if (q == NULL) {
        return NULL;
    }

    q->capacity = INITIAL_CAPACITY;
    q->a = (char*)malloc(q->capacity * sizeof(char));
    
    if (q->a == NULL) {
        free(q);
        return NULL;
    }

    q->front = 0;
    q->rear = 0;
    q->size = 0;

    return q;
}

void dsQueue(CharQueueADT *pq) {
    if (pq == NULL) {
        return;
    }

    if (*pq == NULL) {
        return;
    }

    free((*pq)->a);
    free(*pq);
    *pq = NULL;
}

_Bool enqueue(CharQueueADT q, const char e) {
    if (q == NULL) {
        return 0;
    }

    if (q->size == q->capacity) {
        int new_capacity = q->capacity * 2;
        char* new_array = (char*)malloc(new_capacity * sizeof(char));
        
        if (new_array == NULL) {
            return 0;
        }

        for (int i = 0; i < q->size; ++i) {
            new_array[i] = q->a[(q->front + i) % q->capacity];
        }

        free(q->a);
        q->a = new_array;
        q->capacity = new_capacity;
        q->front = 0;
        q->rear = q->size;
    }

    q->a[q->rear] = e;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;

    return 1;
}

_Bool dequeue(CharQueueADT q, char* res) {
    if (q == NULL) {
        return 0;
    }

    if (q->size == 0) {
        return 0;
    }

    *res = q->a[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    if (q->capacity > INITIAL_CAPACITY && q->size <= q->capacity / 4) {
        int new_capacity = q->capacity / 2;

        if (new_capacity < INITIAL_CAPACITY) {
            new_capacity = INITIAL_CAPACITY;
        }

        char* new_array = (char*)malloc(new_capacity * sizeof(char));
        
        if (new_array != NULL) {
            for (int i = 0; i < q->size; ++i) {
                new_array[i] = q->a[(q->front + i) % q->capacity];
            }

            free(q->a);
            q->a = new_array;
            q->capacity = new_capacity;
            q->front = 0;
            q->rear = q->size;
        }
    }

    return 1;
}

_Bool isEmpty(CharQueueADT q) {
    if (q == NULL) {
        return 1;
    }

    if (q->size == 0) {
        return 1;
    }

    return 0;
}

int size(CharQueueADT q) {
    if (q == NULL) {
        return 0;
    }

    return q->size;
}

_Bool peek(CharQueueADT q, int position, char *res) {
    if (q == NULL) {
        return 0;
    }

    if (position < 0) {
        return 0;
    }

    if (position >= q->size) {
        return 0;
    }

    *res = q->a[(q->front + position) % q->capacity];
    return 1;
}
