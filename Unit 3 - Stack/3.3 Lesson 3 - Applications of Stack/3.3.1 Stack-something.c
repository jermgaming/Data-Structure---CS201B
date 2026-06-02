// Stack implementation in C

#include <stdio.h>

#define MAX 100

typedef struct {
	int items[MAX];
	int top;
} Stack;

void init(Stack *s) {
	s->top = -1;
}

int isEmpty(const Stack *s) {
	return s->top == -1;
}

int isFull(const Stack *s) {
	return s->top == MAX - 1;
}

void push(Stack *s, int value) {
	if (isFull(s)) {
		printf("Stack overflow\n");
		return;
	}
	s->items[++s->top] = value;
}

int pop(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack underflow\n");
		return -1;
	}
	return s->items[s->top--];
}

int peek(const Stack *s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}
	return s->items[s->top];
}

void display(const Stack *s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return;
	}

	printf("Stack elements: ");
	for (int i = s->top; i >= 0; i--) {
		printf("%d ", s->items[i]);
	}
	printf("\n");
}

int main(void) {
	Stack s;
	init(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	display(&s);
	printf("Top element: %d\n", peek(&s));
	printf("Popped element:is %d\n", pop(&s));
	display(&s);

	return 0;
}
