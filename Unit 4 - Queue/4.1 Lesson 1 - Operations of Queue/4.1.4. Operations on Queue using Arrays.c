#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x){
	// write your code here to enqueue an element
	if(rear+1==MAX){
		printf("Queue is overflow.\n");
		return;
	}
	if(front==-1){
		front=0;
	}
	rear++;
	queue[rear]=x;
	printf("Successfully inserted.\n");
	
}
void dequeue() {
	// write your code here to dequeue an element
	if(front==-1 | front>rear){
		printf("Queue is underflow.\n");
		return;
	}
	printf("Deleted element = %d\n",queue[front]);
	front++;

	if(front>rear){
		front=-1;
		rear=-1;
	}
	
}
void display() {
	// write your code here to display the queue
	if(front==-1 || front>rear){
		printf("Queue is empty.\n");
	}else{
		int temp=front;
		printf("Elements in the queue : ");
		while(temp<=rear){
			printf("%d ",queue[temp]);
			temp++;
		}
		printf("\n");
	}
}
void size() {
	// write your code here to get the size of the queue
	if(front==-1 || front>rear){
		printf("Queue size : %d\n",0);
	}else{
		printf("Queue size : %d\n",rear-front+1);
	}
}
void isEmpty() {
	// write your code here to check whether the queue is empty not
	if(front==-1 || front>rear){
		printf("Queue is empty.\n");
	}else {
		printf("Queue is not empty.\n");
	}
}