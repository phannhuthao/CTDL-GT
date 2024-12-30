#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Deque;
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->rear == dq->front - 1);
}

void addFront(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hàng đợi đầy! Không thể thêm phần tử.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = data;
    printf("Đã thêm phần tử vào đầu: %d\n", data);
}

void addRear(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Hàng đợi đầy! Không thể thêm phần tử.\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = data;
    printf("Đã thêm phần tử vào cuối: %d\n", data);
}

void removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hàng đợi rỗng! Không thể lấy phần tử ra.\n");
        return;
    }
    printf("Lấy ra phần tử từ đầu: %d\n", dq->items[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hàng đợi rỗng! Không thể lấy phần tử ra.\n");
        return;
    }
    printf("Lấy ra phần tử từ cuối: %d\n", dq->items[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Hàng đợi hiện tại: []\n");
        return;
    }
    printf("Hàng đợi hiện tại: [");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d, ", dq->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d]\n", dq->items[dq->rear]);
}

int main() {
    Deque dq;
    initDeque(&dq);

    addFront(&dq, 10);
    addRear(&dq, 20);
    addFront(&dq, 5);

    printDeque(&dq);

    removeFront(&dq);
    printDeque(&dq);

    removeRear(&dq);
    printDeque(&dq);

    return 0;
}
