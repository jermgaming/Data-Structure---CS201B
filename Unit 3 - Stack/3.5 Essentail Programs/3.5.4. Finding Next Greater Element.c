// Type Content here...
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int *arr=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int next=-1;
	int *arrNext=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				arrNext[i]=arr[j];
				break;
			}else{
				arrNext[i]=-1;
			}
		}
	}
	arrNext[n-1]=-1;
	for(int i=0;i<n;i++){
		printf("%d ",arrNext[i]);
	}
	return 0;
}