#include <ctype.h>
#include <stdio.h>
#define STACK_MAX_SIZE 20
//Declare the required stack variables.
int arr[STACK_MAX_SIZE];
int top=-1;

//Return 1 if stack is empty else return 0.
int isEmpty() {
	if(top==-1){
		return 1;
	}else {
		return 0;
	}
}

//Push the character into stack
void push(int x) {
	arr[++top]=x;
}

//pop a character from stack
int pop() {
	return arr[top--];
}

void peek(){
	if(top==-1){
		printf("Stack is empty");
	}else {
		printf("%d \n",arr[top]);
	}
}
void evaluatePostfix(char * e) {
	int temp=0;
	int i=0;
	while(e[i]!='\0'){
		if(e[i]<='9' && e[i]>='0'){
			push(e[i]-'0');
			temp++;
			//printf("%d ",e[i]-'0');
		}else {
			if(temp<2){
				printf("Invalid postfix expression.\n");
				return;
			}
			int op2=pop();
			int op1=pop();
			temp-=2;
			if(e[i]=='+'){
				push(op1+op2);
			}else {
				push(op1-op2);
			}

			temp++;
		}
		//peek();
		i++;
		
	}
	if(temp!=1){
		printf("Invalid postfix expression.\n");
		return;
	}
	printf("Result : %d\n",pop());
}


int main() {
	char exp[20];
	char *e, x;
	printf("Enter the postfix expression : ");
	scanf("%s",exp);
	e = exp;
	evaluatePostfix(e);

}