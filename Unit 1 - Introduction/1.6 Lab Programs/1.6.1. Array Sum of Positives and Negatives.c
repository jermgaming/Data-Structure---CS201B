// Type Content here...
#include<stdio.h>
#include<stdlib.h>
int posSum(int arr[],int n){
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			ans+=arr[i];
		}
	}
	return ans;
}

int negSum(int arr[],int n){
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			ans+=arr[i];
		}
	}
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int *arr=malloc(n*sizeof(int));

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	int pos=posSum(arr,n);
	int neg=negSum(arr,n);
	printf("%d\n",pos);
	printf("%d\n",neg);
	return 0;
}