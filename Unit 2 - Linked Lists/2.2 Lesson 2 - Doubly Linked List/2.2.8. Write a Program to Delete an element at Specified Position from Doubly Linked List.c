struct node {
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node * NODE;

NODE createNodeInDLL(int x) {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->data=x;
	return temp;
}

void traverseListInDLL(NODE first) {
	NODE lastNode = first;
	while (lastNode != NULL) {
		printf("%d <--> ", lastNode -> data);
		lastNode = lastNode -> next;
	}
	printf("NULL\n");
}

NODE insertAtEndInDLL(NODE first, int x) {
	NODE newNode=createNodeInDLL(x);
	if(!first) return newNode;
	NODE temp=first;
	while(temp->next){
		temp=temp->next;
	}
	newNode->prev=temp;
	temp->next=newNode;
	return first;
}

NODE deleteAtPositionInDLL(NODE first, int position) {
	if (first == NULL) {
        printf("List is empty, deletion not possible\n");
        return NULL;
    }
    
    // Check for invalid position
    if (position < 1) {
        printf("Invalid position! Position must be >= 1\n");
        return first;
    }
	
	NODE temp = first;
    
    // Traverse to the node at given position
    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("No such position in DLL so deletion is not possible\n");
            return first;
        }
    }
    
    printf("The deleted element from DLL : %d\n", temp->data);
    
    NODE prev = temp->prev;
    NODE fwd = temp->next;
    
    // Update links
    if (prev)
        prev->next = fwd;
    else {
        // Deleting the first node, update first pointer
        first = fwd;
    }
    
    if (fwd)
        fwd->prev = prev;
    
    // Clean up the deleted node
    temp->prev = NULL;
    temp->next = NULL;
    free(temp);
    
    return first;
}