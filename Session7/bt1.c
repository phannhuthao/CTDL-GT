#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}


void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi day!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->data[++(q->rear)] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }

    int value = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return value;
}

void printQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);


    printf("Cac phan tu trong hang doi: ");
    printQueue(&q);

    printf("Phan tu bi xoa: %d\n", dequeue(&q));
    printf("Phan tu bi xoa: %d\n", dequeue(&q));

    printf("Cac phan tu trong hang doi sau khi xóa: ");
    printQueue(&q);

    return 0;
}
