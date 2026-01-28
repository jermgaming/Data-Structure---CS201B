#include<stdio.h>
#include<conio.h>
#define STACK_MAX_SIZE 30
int arr[STACK_MAX_SIZE];
int top = -1;
void push(long int element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
int pop() {
	int x;
	if(top < 0) {
		printf("Stack is underflow.\n");
		return -1;
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}
void main() {
	int size, index;
	int arr[30];
	printf("Enter the size of the array : ");
	scanf("%d", &size);
		if(size < 0) {
		printf("Invalid input! Size should be greater than 0.\n");
		return;
	}
	for(index = 0; index < size; index++) {
		printf("Enter arr[%d] : ",index);
		scanf("%d",&arr[index]);
	}
	printf("Array before reversing : ");
	for(index = 0; index < size; index++) {
		printf("%d ",arr[index]);
	}
	printf("\n");
	
	//Write the logic for reversing an array using
	//stack and their opertions.
	for(int i=0;i<size;i++){
		push(arr[i]);
	}
	int i=0;
	while(top!=-1){
		arr[i]=pop();
		i++;
	}
	
	printf("Array after reversing : ");
	for(index = 0; index < size; index++) {
		printf("%d ",arr[index]);
	}
	printf("\n");
}