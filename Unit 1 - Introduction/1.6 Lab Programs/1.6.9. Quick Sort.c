#include <stdio.h>


int partition(int arr[],int low,int high){
	int i=low-1;
	int pivot=arr[high];

	for(int j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			//swap(arr[i],arr[j]);
		}
	}

	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	//swap(arr[i+1],arr[high]);
	return i+1;
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
    // Complete the code...
    if(low<high){
		int t=partition(arr,low,high);
		quickSort(arr,low,t-1);
		quickSort(arr,t+1,high);
	}
    
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}