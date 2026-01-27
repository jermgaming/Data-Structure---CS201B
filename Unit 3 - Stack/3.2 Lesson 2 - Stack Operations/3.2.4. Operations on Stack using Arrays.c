//declare the size of the array
int size=10;
//define the top to -1
int arr[10];
int top=-1;
void push(int element) {
	//write your code here to push an element
	if(top==size-1){
		printf("Stack is overflow.\n");
		return;
	}
	arr[++top]=element;
	printf("Successfully pushed.\n");
	
}

void display() {
	//write your code here to display the stack
	if(top==-1){
		printf("Stack is empty.\n");
	}else {
		int temp=top;
		printf("Elements of the stack are : ");
		while(temp>=0){
			printf("%d ",arr[temp--]);
		}
		printf("\n");
	}
	
}

void pop() {
	//write your code here to pop an element
	if(top==-1){
		printf("Stack is underflow.\n");
		return;
	}
	printf("Popped value = %d\n",arr[top--]);
	
}

void peek(){
	//write your code here to find the peek element
	if(top==-1){
		printf("Stack is underflow.\n");
		return;
	}
	printf("Peek value = %d\n",arr[top]);

}

void isEmpty() {
	//write your code here to check whether the stack is empty not
	if(top==-1){
		printf("Stack is empty.\n");
	}else {
		printf("Stack is not empty.\n");
	}
	
}