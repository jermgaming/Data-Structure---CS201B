#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {


// write your code here
	int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int leftArr[n1], rightArr[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[] if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[] if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }


}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {

  // write your code here
  
  if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
  
   
}

// Function to print an array
void printArray(int arr[], int size) {

// write your code here
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

}

int main() {
    int n;
    
    // Input the size of the array
    printf("");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("");
    printArray(arr, n);

    return 0;
}
