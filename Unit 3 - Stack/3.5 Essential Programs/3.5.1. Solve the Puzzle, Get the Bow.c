// Type Content here...

#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	scanf("%s",s);
	int size=0;
	int n;
	scanf("%d",&n);
	while(s[size]!='\0'){
		size++;
	}
	//printf("%d",size);
	if((-n+size)<0){
		printf("Invalid position\n");
	}else{
		printf("%c",s[-n+size]);
	}
	//printf("%c",s[-n+size]);
	return 0;
}