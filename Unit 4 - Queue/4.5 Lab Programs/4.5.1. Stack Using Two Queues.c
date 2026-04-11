// #include<stdio.h>
// # define SIZE 1000
// int queue[SIZE];
// int front=-1;
// int rear=-1;

// void push(int x){
// 	if(rear==SIZE-1) return;
// 	rear++;
// 	queue[rear]=x;
// 	if(front==-1){
// 		front=0;
// 	}
// }

// void pop(){
// 	if(front==-1) return;
// 	front++;
// 	if(front>rear){
// 		front=-1;
// 		rear=-1;
// 	}
	
// }

// int isEmpty(){
// 	return front==-1;
// }

// int peek(){
// 	if(front!=-1){
// 		return queue[front];
// 	}
// 	return -1;
// }
// int main(){
// 	int n;
// 	scanf("%d",&n);
// 	for(int i=0;i<n;i++){
		
// 	}
// 	return 0;
// }


#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",arr[n-1]);
	printf("%d\n",arr[n-1]);
	return 0;
}