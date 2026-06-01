#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20
char stack [STACK_MAX_SIZE];

int top = -1;

//Return 1 if stack is empty else return 0.
int isEmpty() {
	if(top==-1)
        return 1;
    return 0;
}

//Push the character into stack
void push(char x) {
	stack[++top]=x;

}

//pop a character from stack
char pop() {
	return stack[top--];
}

// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is '*' or '/' or '%'
int priority(char x) {
	if(x=='(') return 0;
    if(x=='+'|| x=='-') return 1;
    if(x=='*'||x=='/'||x=='%') return 2;
    return -1;
}

//Output Format
//if expression is correct then output will be Postfix Expression : <postfix notation>
//If expression contains invalid operators then output will be "Invalid symbols in infix expression. Only alphanumberic and { '+', '-','*', '%%', '/' } are allowed."
//If the expression contains unbalanced paranthesis the output will be "Invalid infix expression : unbalanced parenthesis."
void convertInfix(char * e) {
	char ans[20];
    int i,k=0;
    int balance=0;
    
    for(i=0;e[i]!='\0';i++){
        if(!((e[i]>='A' && e[i]<='Z') || (e[i]>='a'&& e[i]<='z') || (e[i]>='0' && e[i]<='9')||
             e[i]=='+'||e[i]=='-'||e[i]=='*'||e[i]=='%'||e[i]=='/'||e[i]=='('||e[i]==')')){
            printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed.\n");
            return;
        }
        if (e[i]=='(')
            balance++;
        if(e[i]==')')
            balance--;
    }
    
    if(balance!=0){
        printf("Invalid infix expression : unbalanced parenthesis.\n");
        return;
    }
    
    for(i=0;e[i]!='\0';i++){
        if((e[i]>='A'&& e[i]<='Z') || (e[i]>='a' && e[i]<='z') || (e[i]>='0' && e[i]<='9'))
            ans[k++]=e[i];
        else if(e[i]=='(')
            push(e[i]);
        else if(e[i]==')'){
            while(!isEmpty() && stack[top]!='(')
                ans[k++]=pop();
            pop(); // Remove the '(' from stack
        }else{
            // Check if it's a valid operator
            if(priority(e[i]) == -1) {
                printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed.\n");
                return;
            }
            while(!isEmpty() && priority(stack[top])>=priority(e[i])){
                ans[k++]=pop();
            }
            push(e[i]);
        }
    }
    while(!isEmpty())
        ans[k++]=pop();
    ans[k]='\0';
    printf("Postfix expression : %s\n",ans);
}
