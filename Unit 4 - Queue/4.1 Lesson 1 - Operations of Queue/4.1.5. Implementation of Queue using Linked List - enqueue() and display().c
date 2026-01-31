struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *Q;
Q front = NULL, rear = NULL;

void enqueue(int ele) {
	printf("Successfully inserted.\n");
	if(front==NULL && rear==NULL){
		rear=malloc(sizeof(struct queue));
		rear->next=NULL;
		rear->data=ele;
		front=rear;
		return;
	}
	struct queue* temp=malloc(sizeof(struct queue));
	temp->next=NULL;
	temp->data=ele;
	rear->next=temp;
	rear=rear->next;
	return;
}

void display() {
	struct queue* temp=front;
	printf("Elements in the queue : ");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
