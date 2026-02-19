struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

NODE createNode() {
	struct node* NODE=malloc(sizeof(struct node));
	NODE->next=NULL;
	return NODE;
}