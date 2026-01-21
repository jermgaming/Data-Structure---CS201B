#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int *arr=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int t;
	scanf("%d",&t);
	int s=0,e=n-1;
	int ans;
	while(s<=e){
		int mid=(s+e)/2;
		if(arr[mid]==t){
			ans=mid;
			break;
		}else if(arr[mid]>t){
			ans=mid;
			e=mid-1;
		}else{
			ans=mid;
			s=mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}