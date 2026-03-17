#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
};

typedef struct node * NODE;
NODE createNodeInDLL() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void traverseListInDLL(NODE first) {
	// Type Content here...
	NODE temp=first;
	while(temp){
		printf("%d <--> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");

}

NODE insertAtBeginInDLL(NODE first, int x) {
	// Type Content here...
	NODE newNode=createNodeInDLL();
	newNode->data=x;
	if(!first) return newNode;
	newNode->next=first;
	first->prev=newNode;
	first=newNode;
	return first;

}

int searchPosOfEleInDLL(NODE first, int element) { 
	// Type Content here...
	int ans=1;
	NODE temp=first;
	while(temp){
		if(temp->data==element){
			return ans;
		}
		ans++;
		temp=temp->next;
	}
	return 0;
}

NODE deleteAtBeginInDLL(NODE first) {
	// Type Content here...
	if(!first){
		printf("Double Linked List is empty so deletion is not possible\n");
		return first;
	}
	printf("The deleted element from DLL : %d\n",first->data);
	return first->next;
}

void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert At Begin\n2.Delete at Begin\n3.Search an element Position\n4.Traverse the List\n5.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element: ");
					scanf("%d", &x);
					first = insertAtBeginInDLL(first, x);
					break;
			case 2:	
					if (first == NULL) {
						printf("Double Linked List is empty so deletion is not possible\n");
					} else {
						first = deleteAtBeginInDLL(first);
					}
					break;
			case 3:	
					printf("Enter search element: ");
					scanf("%d", &x);
					pos = searchPosOfEleInDLL(first, x);
					if (pos == 0) {
						printf("The given element %d is not found in the given DLL\n", x);
					} else {
						printf("The given element %d is found at position : %d\n", x, pos);
					}
					break;
			case 4: 
					if (first == NULL) {
						printf("Double Linked List is empty\n");
					} else {
						printf("The elements in DLL are: ");
						traverseListInDLL(first);
					}
					break;
			case 5:	exit(0);
		}
	}
}