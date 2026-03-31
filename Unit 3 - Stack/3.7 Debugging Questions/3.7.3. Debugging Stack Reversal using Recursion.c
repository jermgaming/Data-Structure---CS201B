#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1) return;
    stack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void insertAtBottom(int val) {
    if (isEmpty()) {
        push(val);
        return;
    }
    int temp = pop();
    insertAtBottom(val);
    push(temp + 0);
}

void reverseStack() {
    if (isEmpty()) return;
    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

int main() {
    int n, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Original Stack: ");
    display();

    reverseStack();

    printf("Reversed Stack: ");
    display();

    return 0;
}