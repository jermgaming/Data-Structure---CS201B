// Type Content here...
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int fear[n];
	fear[n-1]=1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				fear[i]=j+1-i;
				break;
			}
			fear[i]=1;
		}
	}
	int ANS;
	for(int i=0;i<n;i++){
		ANS=ANS*fear[i];
	}
	printf("%d\n",ANS);
	return 0;
}