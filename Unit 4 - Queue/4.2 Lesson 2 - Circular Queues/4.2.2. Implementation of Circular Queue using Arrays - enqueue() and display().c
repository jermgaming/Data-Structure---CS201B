#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
	if(rear==MAX-1){
		printf("Circular queue is overflow.\n");
		return;
	}
	queue[++rear]=x;
	if(front==-1) front++;
	printf("Successfully inserted.\n");
}

void display() {
	if(front==-1){
		printf("Circular queue is empty.\n");
	}else {
		printf("Elements in the circular queue : ");
		for(int i=front;i<=rear;i++){
			printf("%d ",queue[i]);
		} printf("\n");
	}
}