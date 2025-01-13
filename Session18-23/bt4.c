#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Đã thêm %d vào hàng đợi.\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng, không thể lấy phần tử!\n");
        return -1;
    }
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Đã lấy %d khỏi hàng đợi.\n", value);
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng, không có phần tử ở đầu!\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Các phần tử trong hàng đợi: ");
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    do {
        printf("\nChọn thao tác:\n");
        printf("1. Thêm phần tử vào hàng đợi (enqueue)\n");
        printf("2. Lấy phần tử khỏi hàng đợi (dequeue)\n");
        printf("3. Xem phần tử ở đầu hàng đợi (peek)\n");
        printf("4. Kiểm tra hàng đợi rỗng\n");
        printf("5. In hàng đợi\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Phần tử ở đầu hàng đợi là: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty(&q)) {
                    printf("Hàng đợi rỗng.\n");
                } else {
                    printf("Hàng đợi không rỗng.\n");
                }
                break;

            case 5:
                display(&q);
                break;

            case 6:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 6);

    return 0;
}
