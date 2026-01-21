#include<stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int x1,y1,x2,y2;
	int ans=0;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=x1-1;i<x2;i++){
		for(int j=y1-1;j<y2;j++){
			ans+=arr[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
}