#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Ngan xep day.\n");
        return;
    }
    stack[++top] = value;
}

void printStack() {
    if (isEmpty()) {
        printf("Ngan xep rong.\n");
        return;
    }

    printf("Cac phan tu trong ngan xep tu tren xuong duoi la: \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Ngan xep rong.\n");
        return;
    }

    int value = stack[top];
    top--;
    printf("Phan tu da xoa: %d\n", value);
}

int main() {
    int n,  value;

    printf("Nhap so luong phan tu trong ngan xep: ");
    scanf("%d", &n);

    if(n > 100) {
        printf("Gia tri n phai be hon 100");
        return 0;
    }

    for(int i = 0; i < n ; i++) {
        printf("Phan tu thu: %d ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printStack();

    pop();
    printStack();

    return 0;
}
