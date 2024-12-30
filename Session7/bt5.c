#include <stdio.h>
#include <string.h>

#define MAX 5


typedef struct {
    int priority;
    char data[50];
} PriorityQueueItem;

typedef struct {
    PriorityQueueItem items[MAX];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void enqueue(PriorityQueue *pq, int priority, const char *data) {
    if (pq->size == MAX) {
        printf("Hàng đợi đầy! Không thể thêm phần tử.\n");
        return;
    }


    int i = pq->size - 1;
    while (i >= 0 && pq->items[i].priority > priority) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }

    pq->items[i + 1].priority = priority;
    strcpy(pq->items[i + 1].data, data);
    pq->size++;

    printf("Đã thêm phần tử (%d, \"%s\").\n", priority, data);
}

void dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hàng đợi rỗng! Không thể lấy phần tử.\n");
        return;
    }

    printf("Đã lấy ra phần tử: \"%s\" (ưu tiên %d).\n",
           pq->items[0].data, pq->items[0].priority);

    for (int i = 1; i < pq->size; i++) {
        pq->items[i - 1] = pq->items[i];
    }

    pq->size--;
}

void printQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }

    printf("Trạng thái hàng đợi:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, \"%s\") ", pq->items[i].priority, pq->items[i].data);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    // Thêm các phần tử vào hàng đợi
    enqueue(&pq, 2, "Task A");
    printQueue(&pq);

    enqueue(&pq, 1, "Task B");
    printQueue(&pq);

    enqueue(&pq, 3, "Task C");
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    dequeue(&pq);
    printQueue(&pq);

    return 0;
}
