// Type Content here...
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
int main(){
	int n;
	scanf("%d",&n);
	struct node* head=NULL;
	while(n--){
		int data;
		scanf("%d",&data);
		//head=createNode(head,data);
	}
	int pos=0;
	scanf("%d",&pos);
	if(pos){
		printf("Given List has cycle: Yes\n");
	}else {
		printf("Given List has cycle: No\n");
	}
	return 0;
}