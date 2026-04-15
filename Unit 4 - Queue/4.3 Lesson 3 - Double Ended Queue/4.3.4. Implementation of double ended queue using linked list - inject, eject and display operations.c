struct queue {
	int data;
	struct queue *next;
};
typedef struct queue *DeQueue;
DeQueue front = NULL, rear = NULL;

void inject(int ele) {
	struct queue* newNode=malloc(sizeof(struct queue));
	newNode->data=ele;
	if(front==NULL && rear==NULL){
		front=newNode;
		rear=newNode;
		printf("Successfully inserted at rear side.\n");
		return;
	}
	rear->next=newNode;
	rear=rear->next;
	printf("Successfully inserted at rear side.\n");
}
void eject() {
	if(rear==NULL){
		printf("Dequeue is underflow.\n");
		return;
	}
	struct queue* temp=front;
	while(temp->next!=rear){
		temp=temp->next;
	}
	if(!temp->next){
		printf("Deleted element %d from the rear side.\n",temp->data);
		front=NULL;
		rear=NULL;
		return;
	}
	printf("Deleted element %d from the rear side.\n",temp->next->data);
	temp->next=NULL;
	rear=temp;
}
void display() {
	struct queue* temp=front;
	if(front==NULL){
		printf("Double ended queue is empty.\n");
		return;
	}
	printf("Elements in the double ended queue : \n");
	while(temp!=rear){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d ",temp->data);
	printf("\n");
}