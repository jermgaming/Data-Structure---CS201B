struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNode() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtBeginInCLL(NODE first, int x) {
    if(first == NULL) {
        first = createNode();
        first->data = x;
        first->next = first;
        return first;
    }
    
    NODE newNode = createNode();
    newNode->data = x;
	
    newNode->next = first->next;
    first->next = newNode;
    
    int tempData = first->data;
    first->data = newNode->data;
    newNode->data = tempData;
    
    return first;
}

int searchPosOfEleInCLL(NODE first, int key) {
	if(!first) return 0;
	NODE temp=first;
	int pos=1;
	//int found=-1;
	do{
		if(temp->data==key){
			return pos;
		}
		temp=temp->next;
		pos++;
	}while(temp!=first);
	
	return 0;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}