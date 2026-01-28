#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
	// Write your code here...
	
	if((*head)==NULL){
		(*head)=createNode(data);
		return;
	}
	struct Node* temp=*(head);
	while(temp->next){
		temp=temp->next;
	}
	struct Node* newNode=createNode(data);
	temp->next=newNode;
	return;
}

int searchNode(struct Node* head, int data) {
	// Write your code here...
	
	struct Node* temp=head;
	while(temp){
		if(temp->data==data){
			return 1;
		}
		temp=temp->next;
	}
	return 0;
	
	
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    printf("Number of nodes: ");
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);  // Inserting at the end
    }

    while (1) {
        printf("1. Search\n");
        printf("2. Print List\n");
        printf("3. Insert at End\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &data);
                if (searchNode(head, data)) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 2:
                printList(head);
                break;
            case 3:
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("%d inserted at end\n", data);
                break;
            case 4:
                // Clean up memory before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid\n");
        }
    }

    return 0;
}