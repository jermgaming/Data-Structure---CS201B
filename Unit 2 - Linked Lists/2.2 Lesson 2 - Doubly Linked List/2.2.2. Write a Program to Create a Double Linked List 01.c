struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL() {
	NODE head=malloc(sizeof(struct node));
	head->prev=NULL;
	head->next=NULL;
	return head;
}