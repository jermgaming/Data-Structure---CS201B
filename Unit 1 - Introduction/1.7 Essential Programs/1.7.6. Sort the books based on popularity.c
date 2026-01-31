// write your code here
#include<stdio.h>

void bubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int n;
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid number\n");
		return 0;
	}
	int *arr=malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	printf("Original Popularity Scores: ");
	printArr(arr,n);
	bubbleSort(arr,n);
	printf("Sorted Popularity Scores: ");
	printArr(arr,n);
	return 0;
}