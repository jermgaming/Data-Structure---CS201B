#include<stdio.h>
void print(int arr[],int front,int rear){
	int temp=front;
	if(front==-1) return;
	while(temp!=rear+1){
		printf("%d ",arr[temp]);
		temp++;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int front=-1;
	int rear=-1;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		print(arr,front,rear);
		printf("Enqueuing %d\n",x);
		if(front==-1){
			front++;
			rear++;
			arr[rear]=x;
		}else {
			rear++;
			arr[rear]=x;
		}
	}
	return 0;
}