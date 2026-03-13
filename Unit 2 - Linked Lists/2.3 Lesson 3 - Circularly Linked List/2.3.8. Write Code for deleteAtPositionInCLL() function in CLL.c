	struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

NODE createNodeInCLL() {
	NODE temp;
	temp = (NODE) malloc(sizeof(struct node));
	temp -> next = NULL;
	return temp;
}

NODE insertAtEndInCLL(NODE first, int x) {
	NODE new = createNodeInCLL();
	new->data = x;
	if(!first){
		new->next = new;
		return new;
	}
	new->next = first->next;
	first->next = new;
	new->data = first->data;
	first->data = x;
	return first->next;
}
NODE deleteAtPositionInCLL(NODE first, int pos) {

    if (first == NULL) {
        printf("CLL is empty\n");
        return NULL;
    }

    if (first->next == first && pos == 1) {
        printf("The deleted element from CLL : %d\n", first->data);
        free(first);
        return NULL;
    }

    if (pos == 1) {
        printf("The deleted element from CLL : %d\n", first->data);

        NODE temp = first->next;
        first->next = temp->next;
        first->data = temp->data;

        free(temp);
        return first;
    }

    NODE temp = first;
    int count = 1;

    while (temp->next != first) {
        count++;
        temp = temp->next;
    }

    if (pos > count || pos <= 0) {
        printf("No such position in CLL so deletion is not possible\n");
        return first;
    }

    int i = 1;
    temp = first;

    while (i < pos - 1) {
        i++;
        temp = temp->next;
    }

    NODE t = temp->next;
    temp->next = t->next;

    printf("The deleted element from CLL : %d\n", t->data);

    free(t);
    return first;
}

void traverseListInCLL(NODE first) {
	NODE temp = first;
	do {
		printf("%d --> ", temp -> data);
		temp = temp -> next;
	} while (temp != first);
	printf("\n");
}