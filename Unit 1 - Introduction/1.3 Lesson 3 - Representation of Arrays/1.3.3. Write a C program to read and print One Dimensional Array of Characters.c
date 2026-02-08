#include<stdio.h>
int main(){
	printf("Enter size of the array : ");
	int n;
	scanf("%d",&n);
	char arr[n];
	printf("Enter array elements : ");
	for(int i=0;i<n;i++){
		scanf(" %c",&arr[i]);
	}

	printf("The given character array elements : ");

	for(int i=0;i<n;i++){
		printf("%c ",arr[i]);
	}
	printf("\n");
}