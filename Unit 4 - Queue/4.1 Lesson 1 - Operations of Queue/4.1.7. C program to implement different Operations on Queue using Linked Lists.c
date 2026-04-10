struct queue {
	int data;
	struct queue *next;
};

typedef struct queue *Q;
Q front = NULL, rear = NULL;

void enqueue(int element) {
	struct queue *node=malloc(sizeof(struct queue));
	node->next=NULL;
	node->data=element;
	if(front==NULL && rear==NULL){
		front=node;
		rear=node;
	}else {
		rear->next=node;
		rear=rear->next;
	}
	printf("Successfully inserted.\n");

}
					
void dequeue() {
	if(front==NULL && rear==NULL){
		printf("Queue is underflow.\n");
		return;
	}
	printf("Deleted value = %d\n",front->data);
	front=front->next;
	if(front==NULL){
		front=NULL;
		rear=NULL;
	}

}

void size() {
	struct queue *temp=front;
	int size=0;
	for(;temp!=NULL;temp=temp->next){
		size++;
	}

	printf("Queue size : %d\n",size);

}

void isEmpty() {
	if(front==NULL){
		printf("Queue is empty.\n");
	}else {
		printf("Queue is not empty.\n");
	}
	
}

void display() {
	if(front == NULL) {
		printf("Queue is empty.\n");
	} else {
		Q temp = front;
		printf("Elements in the queue : ");
		while(temp  != NULL) {
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}

