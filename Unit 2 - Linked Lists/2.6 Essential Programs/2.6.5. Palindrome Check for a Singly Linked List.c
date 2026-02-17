#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* insertIntoTail(struct node* head,int data){
	if(!head){
		head=malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
		return head;
	}
	struct node* temp=head;
	while(temp->next){
		temp=temp->next;
	}

	struct node* newNode=malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->data=data;
	temp->next=newNode;
	return head;
}
struct node* rev(struct node* head){
	struct node* prev=NULL;
	struct node* curr=head;
	while(curr){
		struct node* forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	return prev;
}

int checkPallindrome(struct node* head){
	if(!head) return 1;
	struct node* slow=head;
	struct node* fast=head;
	struct node* prev=NULL;
	while(fast && fast->next){
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	prev->next=NULL;
	struct node* t1=rev(slow);
	struct node* t2=head;
	while(t1 && t2){
		if(t1->data!=t2->data){
			//printf("%d %d\n",t1->data,t2->data);
			return 0; 
		}
		t1=t1->next;
		t2=t2->next;
	}
	return 1;
}
void solve(int arr[],int t){
	struct node* head=NULL;
	int x;
	scanf("%d",&x);
	while(x!=-1){
		head=insertIntoTail(head,x);
		scanf("%d",&x);
	}
	//if(!head) printf("hi");
	arr[t]=checkPallindrome(head);
}

int main(){
	int t;
	scanf("%d",&t);
	int ans[t];
	for(int i=0;i<t;i++){
		solve(ans,i);
	}

	for(int i=0;i<t;i++){
		if(ans[i]==0){
			printf("false\n");
		}else {
			printf("true\n");
		}
		//printf("%d ",ans[i]);
	}
	return 0;
}