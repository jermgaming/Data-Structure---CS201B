#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

// Stack implementation for storing brackets
char stack[MAX_STACK_SIZE];

int top=-1;

//write your code here
int isEmpty(){
	if(top==-1) return 1;
	return 0;
}

void push(char i){
	stack[++top]=i;
}

char getTop(){
	if(top==-1){
		printf("Stack is empty");
		return 'a';
	}
	return stack[top];
}

void pop(){
	top--;
}
int isValid(char *s){
	top=-1;
	int i=0;
	while(s[i]!='\0'){
		//printf("hello");
		if(s[i]== '(' || s[i]== '{' || s[i]== '['){
			//printf("push");
			push(s[i]);
		}else {
			if(isEmpty() && (s[i]== ')' || s[i]== '}' || s[i]== ']')){
				//printf("empty");
				return false;
			}else if((s[i]==')' && getTop()=='(' ) || (s[i]=='}' && getTop()=='{' ) || (s[i]==']' && getTop()=='[')){
				pop();
				//printf("pop");
			}else{
				//printf("end");
				//return true;
			}
		}
		i++;
	}
	//printf("last");
	//printf("%c",getTop());
	return top==-1;
}



int main() {
    char s[MAX_STACK_SIZE];
    printf("");
    scanf("%s", s);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}