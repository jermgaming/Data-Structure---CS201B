// Type Content here...
#include<stdio.h>
#include<stdlib.h>
void solve(){
	int n,sum=0;
	scanf("%d",&n);
	int *arr=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	for(int i=0;i<n;i++){
		printf("%d ",sum-arr[i]);
	}printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}