//Write the code here
#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int narr[n];
	narr[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--){
		narr[i]=arr[i+1]+arr[i];
	}

	for(int i=0;i<n;i++){
		printf("%d ",narr[i]);
	}
	
	return 0;
}