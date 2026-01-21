#define STACK_MAX_SIZE 10

int arr[STACK_MAX_SIZE];
int top = -1;

void push(int element) {
	if(top==(STACK_MAX_SIZE-1)){
		printf("Stack is overflow\n");
		return;
	}else {
		top++;
		arr[top]=element;
		printf("Successfully pushed.\n");
	}
}

void display() {
	int temp=top;
	if(temp==-1){
		printf("Stack is empty.\n");
	}else {
		printf("Elements of the stack are : ");
		while(temp>=0){
			printf("%d ",arr[temp]);
			temp=temp-1;
		}printf("\n");
	}
}