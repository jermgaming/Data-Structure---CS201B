// Type your content here...
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int s;
	scanf("%d",&s);
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==s){
				printf("%d %d\n",arr[i],arr[j]);
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}