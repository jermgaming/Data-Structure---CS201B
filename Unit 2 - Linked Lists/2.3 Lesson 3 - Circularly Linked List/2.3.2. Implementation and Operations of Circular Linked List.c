struct node {
	int data;
	struct node * next;
};
typedef struct node * NODE;

NODE createNodeInCLL() {
	NODE head=malloc(sizeof(struct node));
	head->next=NULL;
	return head;
}