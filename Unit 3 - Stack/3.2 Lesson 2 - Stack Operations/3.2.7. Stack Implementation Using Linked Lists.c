struct stack {
	int data;
	struct stack *next;
};

typedef struct stack *stk;
stk top = NULL;

void push(int x) {
	printf("Successfully pushed.\n");
	if(top==NULL){
		top=malloc(sizeof(struct stack));
		top->next=NULL;
		top->data=x;
		return;
	}
	struct stack* temp=malloc(sizeof(struct stack));
	temp->next=top;
	temp->data=x;
	top=temp;
	
	
}

void pop() {
	if(top==NULL){
		printf("Stack is underflow.\n");
		return;
	}else {
		struct stack* temp=top;
		top=top->next;
		temp->next=NULL;
		printf("Popped value = %d\n",temp->data);
		free(temp);
		temp=NULL;
	}

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
