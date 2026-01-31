#include <stdio.h>

// Type Content here...


void selectionSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main() {
	int n;
	// Input: Number of elements in the array
	scanf("%d", &n);
	
	int arr[n], i;
	// Input: Elements of the array
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	// Call the selectionSort function to sort the array
	selectionSort(arr, n);
	
	// Output: Sorted array
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
