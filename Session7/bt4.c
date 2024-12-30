#include <stdio.h>

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

int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng! Không thể trả về phần tử đầu tiên.\n");
        return -1;
    }

    return q->data[q->front];
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
    printf("Phần tử đầu tiên (peek): %d\n", peek(&q));

    enqueue(&q, 20);
    printf("Phần tử đầu tiên (peek): %d\n", peek(&q));

    enqueue(&q, 30);
    printf("Phần tử đầu tiên (peek): %d\n", peek(&q));

    printQueue(&q);

    int dequeuedValue = dequeue(&q);
    if (dequeuedValue != -1) {
        printf("Đã lấy phần tử: %d\n", dequeuedValue);
    }

    printf("Phần tử đầu tiên (peek): %d\n", peek(&q));

    printQueue(&q);

    return 0;
}
