#include<stdio.h>
int main(){
	printf("Enter row and column sizes : ");
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Enter the value of arr[%d][%d] : ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The given matrix is\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",arr[i][j]);
		}printf("\n");
	}
	return 0;
}