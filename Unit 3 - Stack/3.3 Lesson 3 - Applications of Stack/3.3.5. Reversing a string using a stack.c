#include<stdio.h>
#include<string.h>
#define STACK_MAX_SIZE 30
char arr[STACK_MAX_SIZE];
int top = -1;
void push(char element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
char pop() {
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
void reverse(char str[]) { 
	int i=0;
	while(str[i]!='\0'){
		push(str[i]);
		i++;
	}
	i=0;
	while(top!=-1){
		str[i]=pop();
		i++;
	}
}
void main() {
	char ch[80], temp;
	printf("Enter a string : ");
	scanf("%s", ch);
	reverse(ch);
	printf("The reverse of a given string : %s\n", ch);
}