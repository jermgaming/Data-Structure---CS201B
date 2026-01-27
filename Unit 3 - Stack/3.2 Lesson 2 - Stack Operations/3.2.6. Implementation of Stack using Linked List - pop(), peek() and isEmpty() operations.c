#include <stdio.h>
#include <stdlib.h>
struct stack {
	int data;
	struct stack *next;
};

typedef struct stack *stk;
stk top = NULL;


stk pop() {
	if(top==NULL){
		printf("Stack is underflow.\n");
		return NULL;
	}
	struct stack* temp=top;
	printf("Popped value = %d\n",temp->data);
	top=top->next;
	temp->next=NULL;
	free(temp);
	temp=NULL;
	
	return top;
}

void peek() {
	if(top==NULL){
		printf("Stack is underflow.\n");
	}else {
		printf("Peek value = %d\n",top->data);
	}
}


void isEmpty() {
	if(top==NULL){
		printf("Stack is empty.\n");
	}else {
		printf("Stack is not empty.\n");
	}
}

stk push(int x) {
	stk temp;
	temp = (stk)malloc(sizeof(struct stack));
	if(temp == NULL) {
		printf("Stack is overflow.\n");
	} else {
		temp -> data = x;
		temp -> next = top;
		top = temp;
		printf("Successfully pushed.\n");
	}
}

void display() {
	stk temp = top;
	if(temp == NULL) {
		printf("Stack is empty.\n"); 
	} else {
		printf("Elements of the stack are : ");
		while(temp != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}
