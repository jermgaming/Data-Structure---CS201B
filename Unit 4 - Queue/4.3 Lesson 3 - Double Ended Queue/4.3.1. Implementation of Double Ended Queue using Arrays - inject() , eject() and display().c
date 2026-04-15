#define MAX 10
int deQueue[MAX];
int rear =-1,front=-1;
int capacity=0;
void inject(int x) {
	if(capacity==MAX){
		printf("Double ended queue is overflow.\n");
		return;
	}
	rear++;
	deQueue[rear]=x;
	if(front==-1){
		front=0;
	}
	capacity++;
	printf("Successfully inserted at rear side.\n");
}
void eject() {
	if(capacity==0){
		printf("Double ended queue is underflow.\n");
		return;
	}
	printf("Deleted element from the rear side = %d\n",deQueue[rear]);
	rear--;
	capacity--;
}
void display() {
	if(capacity==0){
		printf("Double ended queue is empty.\n");
		return;
	}
	printf("Elements in the double ended queue : ");
	for(int i=front;i<=rear;i++){
		printf("%d ",deQueue[i]);
	}printf("\n");
}