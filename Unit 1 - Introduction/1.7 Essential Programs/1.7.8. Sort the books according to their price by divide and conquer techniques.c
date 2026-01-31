
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(float arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				float temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void printArr(float arr[],int n){
	for(int i=0;i<n;i++){
		printf("%0.2f\n",arr[i]);
	}
	printf("\n");
}
int main(){
	int n;
	printf("Number of books: ");
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid number of books\n");
		return 0;
	}
	float *arr=malloc(n*sizeof(float));
	for(int i=0;i<n;i++){
		printf("Book %d price: ",i+1);
		scanf("%f",&arr[i]);
	}

	bubbleSort(arr,n);
	printf("Sorted list of book prices:\n");
	printArr(arr,n);
	return 0;
}