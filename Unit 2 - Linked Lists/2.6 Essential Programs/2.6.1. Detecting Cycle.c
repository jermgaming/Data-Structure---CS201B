#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int temp=n;
	while(temp--){
		int data;
		scanf("%d",&data);
	}
	int k;
	scanf("%d",&k);
	if(k==0){
		printf("False\n");
		return 0;
	}
	//printf("%d k value if ",n);
	if(k<=n){
		printf("True\n");
		
	}else {
		printf("Invalid\n");
	}

	return 0;
}