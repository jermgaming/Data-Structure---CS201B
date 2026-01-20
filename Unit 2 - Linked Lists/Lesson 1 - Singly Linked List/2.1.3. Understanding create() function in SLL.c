struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

NODE createNode() {
	struct node* temp=malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}