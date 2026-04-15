#define MAX 20
int deQueue	[MAX];
int front = -1, rear = -1;

void push(int x) {
	if(front==-1 || front==0){
		printf("Double ended queue is overflow.\n");
		return;
	}
	front--;
	deQueue[front]=x;
	printf("Successfully inserted at front side.\n");
	return;
}

void pop() {
	if(front==-1){
		printf("Double ended queue is underflow.\n");
		return;
	}
	printf("Deleted element from front side = %d\n",deQueue[front]);
	if(front==rear){
		front=-1;
		rear=-1;
		return;
	}
	front++;
	
	
}

void eject() {
	if (rear == -1) {
		printf("Double ended queue is underflow.\n");	
	} else {
		printf("Deleted element from rear side = %d\n", deQueue[rear]); 
		if (front == rear) {
			front = rear = -1;
		} else {
			rear--;
		}
	}
}
void display() {
	int i;
	if(front == -1 && rear == -1) {
		printf("Double ended queue is empty.");	
	} else {
		printf("Elements in double ended queue : ");
		for(i = front; i <= rear; i++) {
			printf("%d ", deQueue[i]);
		}
	}
	printf("\n");
}
void inject(int x) {
	if (rear == MAX - 1) {
		printf("Double ended queue is overflow.\n");	
	} else {
		rear++;
		deQueue[rear] = x;
		if (front == -1) {
			front = 0;
		}
		printf("Successfully inserted at rear side.\n");
	}
}