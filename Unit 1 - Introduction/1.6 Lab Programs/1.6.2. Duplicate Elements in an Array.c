// Type Content here...
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int *arr=malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int dup=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				dup=1;
				break;
			}
		}
	}
	dup==1?printf("true\n"):printf("false\n");
	return 0;
}