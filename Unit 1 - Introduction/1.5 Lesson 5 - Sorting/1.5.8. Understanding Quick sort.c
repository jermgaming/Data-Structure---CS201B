int partition(int arr[15], int lb, int ub);
void display(int arr[15], int n) {
	int i;
	for (i=0;i<n;i++) // Complete the code in for
		printf("%d ", arr[i]);
	printf("\n");
}
void quickSort(int arr[15], int low, int high) {
	int j;
	if (low<high) { // Write the condition
		j = partition(arr, low, high);
		quickSort(arr,low,j-1); // Call the first partition
		quickSort(arr,j+1,high); // Call the second partition
	}
}
int partition(int arr[15], int lb, int ub) {
	//write your code here..
	int i=lb-1;
	int pivot=arr[ub];
	int j=lb;
	while(j<ub){
		if(arr[j]<pivot){
			i++;
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
		j++;
	}
	int temp=arr[i+1];
	arr[i+1]=arr[ub];
	arr[ub]=temp;
	return i+1;
	
	
}