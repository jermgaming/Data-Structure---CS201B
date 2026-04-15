struct queue {
	int data;
	struct queue *next;
};
typedef struct queue *DeQueue;
DeQueue front = NULL, rear = NULL;

void push(int ele) {
	DeQueue newnode = (DeQueue)malloc(sizeof(struct queue));
	if(newnode == NULL){
		printf("Dequeue is overflow.\n");
		return;
	}
	newnode->data = ele;
	newnode->next = NULL;
	if(front == NULL){
		front = rear = newnode;
	}
	else{
		newnode->next = front;
		front = newnode;
	}
	printf("Successfully inserted at front side.\n");
}

void pop() {
	if(front == NULL){
		printf("Dequeue is underflow.\n");
		return;
	}
	printf("Deleted element %d from the front side.\n",front->data);
	if(front == rear){
		free(front);
		front = rear = NULL;
	}else{
		DeQueue temp = front;
	front = front->next;
	free(temp);
	}
}

void inject(int ele) {
	DeQueue temp = NULL;
	temp = (DeQueue)malloc(sizeof(struct queue));
	if(temp == NULL) {
		printf("Dequeue is overflow.\n");
	} else {
		temp -> data = ele;
		temp -> next = NULL;
		if(front == NULL) {
			front = temp;
		} else {
			rear -> next = temp;
		}
		rear = temp;
		printf("Successfully inserted at rear side.\n");
	}
}

void eject() {
	DeQueue temp = NULL;
	if(rear == NULL) {
		printf("Dequeue is underflow.\n");
	} else {
		temp = front;
		if (front == rear) {
			front = rear = NULL;
		} else {
			while(temp -> next != rear) { 
				temp = temp -> next;
			}
			rear=temp;
			temp = rear -> next;
			rear->next = NULL;
		}
		printf("Deleted element %d from the rear side.\n", temp -> data);
		free(temp);
	}
}

void display() {
	if(front == NULL) {
		printf("Double ended queue is empty.\n");
	} else {
		DeQueue temp = front;
		printf("Elements in the double ended queue : \n");
		while(temp != NULL) { 
			printf("%d ", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}