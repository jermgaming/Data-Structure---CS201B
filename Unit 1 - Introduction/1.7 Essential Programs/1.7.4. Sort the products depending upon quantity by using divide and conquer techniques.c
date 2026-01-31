#include <stdio.h>

// Function to perform modified Bubble Sort on an array of quantities
void bubbleSortWithSmallest(int arr[], int n) {
    // Code here..

  for(int i=0;i<n;i++){
	  for(int j=0;j<n-i-1;j++){
		  if(arr[j]>arr[j+1]){
			  int temp=arr[j];
			  arr[j]=arr[j+1];
			  arr[j+1]=temp;
		  }
	  }
  }
  
  
    
}

int main() {
	int n;
	scanf("%d",&n);
	if(n<=0){
		printf("Invalid number\n");
		return 1;
	}
	int quantities[n];
	for (int i=0;i<n;i++){
		scanf("%d",&quantities[i]);
	}
	printf("Original Quantities: ");
	for (int i = 0; i < n; i++) {
		printf("%d ",quantities[i]);
	}
	printf("\n");
	bubbleSortWithSmallest(quantities,n);
	printf("Sorted Quantities: ");
	for (int i = 0; i < n; i++) {
		printf("%d ",quantities[i]);
	}
	printf("\n");
	return 0;
}
