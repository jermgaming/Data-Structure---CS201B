
#define STACK_MAX_SIZE 10

int arr[STACK_MAX_SIZE];
int top = -1;

void pop() {
	if(top==-1){
		printf("Stack is underflow.\n");
		return;
	}
	printf("Popped value = %d\n",arr[top--]);
}

void peek() {
	if(top==-1){
		printf("Stack is underflow.\n");
		return;
	}
	printf("Peek value = %d\n",arr[top]);
}

void isEmpty() {
	if(top==-1){
		printf("Stack is empty.\n");
	}else{
		printf("Stack is not empty.\n");
	}
}

void push(int element) {
	if(top == STACK_MAX_SIZE - 1) {
		printf("Stack is overflow.\n");
	} else {
		top = top + 1;
		arr[top] = element;
		printf("Successfully pushed.\n");
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
