#include<stdio.h>
#define STACK_MAX_SIZE 100000

int arr[STACK_MAX_SIZE];
int top = -1;

void pop() {
	if(top==-1){
		//printf("Stack is underflow.\n");
	}else{
		top--;
	}
}

void peek() {
	if(top==-1){
		printf("Stack is underflow.\n");
	}else {
		printf("Peek value = %d\n",arr[top]);
	}
}
int Top(){
	return top==-1?-1:arr[top];
}
int isEmpty() {
	return top==-1;
}

void push(int element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
		//printf("Successfully pushed.\n");
	}
}

void display() {
	if (top < 0) {
		printf("Stack is empty.\n");
	} else {
		printf("Elements of the stack are : " );
		for(int i = top; i >= 0; i--) {
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
}


int main(){
	int n;
	scanf("%d",&n);
	int input[n];
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	int ans[n];
	

	for(int i=0;i<n;i++){
		while(!isEmpty() && input[Top()]<=input[i]){
			pop();
		}
		if(isEmpty()){
			ans[i]=i+1;
		}else{
			ans[i]=i-Top();
		}
		push(i);
	}

	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}printf("\n");
	return 0;
}
