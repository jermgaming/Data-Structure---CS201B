#include<stdio.h>
#include<conio.h>
#define STACK_MAX_SIZE 30
long int arr[STACK_MAX_SIZE];
int top = -1;
void push(long int element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
long int pop() {
	long int x;
	if(top < 0) {
		printf("Stack is underflow.\n");
		return -1;
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}
// Implement the factorial program using the stack.
long int factorial(long int n) {
	if(n==0) return 1;
	return n*factorial(n-1);
}
void main() {
	long int n;
	printf("Enter an integer : ");
	scanf("%ld", &n);
	if(n < 0) {
		printf("Invalid input! Only positive numbers are allowed.\n");
		return;
	}
	printf("Factorial of %ld is : %ld\n", n, factorial(n));
}
//comments added