// Type Content here...
#include<stdio.h>
#include<limits.h>

int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int k;
	scanf("%d",&k);
	int ans[n];
	int temp=0;
	for(int i=0;i<n-k+1;i++){
		int maxi=INT_MIN;
		for(int j=i;j<k+i;j++){
			maxi=max(maxi,arr[j]);
			ans[temp]=maxi;
		}
		temp++;
	}
	temp=n-k+1;
	for(int i=0;i<temp;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}