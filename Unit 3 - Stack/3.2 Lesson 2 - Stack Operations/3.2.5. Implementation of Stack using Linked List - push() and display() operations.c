#include <stdio.h>
#include <stdlib.h>
struct stack {
	int data;
	struct stack *next;
};

typedef struct stack *stk;
stk top = NULL;

stk push(int x) {
	printf("Successfully pushed.\n");
	if(top==NULL){
		stk temp=malloc(sizeof(struct stack));
		temp->next=NULL;
		temp->data=x;
		top=temp;
		return top;
	}
	stk temp=malloc(sizeof(struct stack));
	temp->next=top;
	top=temp;
	temp->data=x;
	return top;
}

void display() {
	struct stack* temp=top;
	printf("Elements of the stack are : ");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
