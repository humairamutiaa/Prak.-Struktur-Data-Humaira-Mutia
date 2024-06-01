#include <stdio.h>
#include <stdlib.h>

#define BENAR 1
#define SALAH 0
#define PENUH 10 // Define the maximum size of the queue

struct node {
    int data;
    struct node *next;
};

struct queue {
    int count;
    struct node *front;
    struct node *rear;
};

typedef struct queue queue;

void inisialisasi(queue *q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q) {
    return (q->rear == NULL);
}

void enqueue(queue *q, int value) {
    if (q->count < PENUH) {
        struct node *tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        if (tmp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        tmp->data = value;
        tmp->next = NULL;
        if (!isempty(q)) {
            q->rear->next = tmp;
            q->rear = tmp;
        } else {
            q->front = q->rear = tmp;
        }
        q->count++;
    } else {
        printf("Antrian penuh\n");
    }
}

int dequeue(queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return n;
}

void display(queue *q) {
    struct node *current = q->front;
    if (current == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    queue q;
    inisialisasi(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Queue before dequeue operation:\n");
    display(&q);
    dequeue(&q);
    printf("Queue after dequeue operation:\n");
    display(&q);
    return 0;
}