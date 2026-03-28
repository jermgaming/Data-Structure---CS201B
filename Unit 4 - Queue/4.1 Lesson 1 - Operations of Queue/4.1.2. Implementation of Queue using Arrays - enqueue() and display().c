//Declare Queue Variables
#define MAX 10
int queue[MAX];
int front=-1,back=-1;

//This function should insert the x into the Queue. if success print "Successfully inserted." else "Queue is overflow."
void enqueue(int x) {
	if(back==MAX-1){
		printf("Queue is overflow.\n");
		return;
	}

	
	queue[++back]=x;
	if(front==-1) front++;
	printf("Successfully inserted.\n");
}

//This displays all the elements of the queue.
//If the queue is empty display "Queue is empty."
void display() {
	if(front==-1 || front>back){
		printf("Queue is empty.\n");
		return;
	}
	printf("Elements in the queue : ");
	int temp=front;
	for(int i=front;i<=back;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}