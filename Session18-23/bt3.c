#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct Stack {
    Node *top;
} Stack;


void initStack(Stack *stack) {
    stack->top = NULL;
}


int isEmpty(Stack *stack) {
    return stack->top == NULL;
}


void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không thể lấy phần tử!\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Đã lấy %d khỏi ngăn xếp.\n", value);
    return value;
}


int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không có phần tử trên đỉnh!\n");
        return -1;
    }
    return stack->top->data;
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    Node *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;

    do {
        printf("\nChọn thao tác:\n");
        printf("1. Thêm phần tử vào ngăn xếp (push)\n");
        printf("2. Lấy phần tử khỏi ngăn xếp (pop)\n");
        printf("3. Xem phần tử trên đỉnh ngăn xếp (peek)\n");
        printf("4. Kiểm tra ngăn xếp rỗng\n");
        printf("5. In ngăn xếp\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập giá trị cần thêm: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Phần tử trên đỉnh ngăn xếp là: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty(&stack)) {
                    printf("Ngăn xếp rỗng.\n");
                } else {
                    printf("Ngăn xếp không rỗng.\n");
                }
                break;

            case 5:
                display(&stack);
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
