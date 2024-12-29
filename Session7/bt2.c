#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Hàng đợi đầy!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->data[++(q->rear)] = value;
    printf("Đã thêm phần tử: %d\n", value);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng!\n");
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
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Các phần tử trong hàng đợi: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printQueue(&q);

    int dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("Đã lấy phần tử: %d\n", dequeuedValue);
    }

    printQueue(&q);

    enqueue(&q, 50);

    printQueue(&q);

    return 0;
}
