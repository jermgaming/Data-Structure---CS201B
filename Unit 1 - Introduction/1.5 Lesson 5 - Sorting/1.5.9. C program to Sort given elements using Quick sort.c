void display(int arr[15], int n) {
	//write your code here..
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
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
void quickSort(int arr[15], int low, int high) {
	//write your code here..
	if(low<high){
		int temp=partition(arr,low,high);
		quickSort(arr,low,temp-1);
		quickSort(arr,temp+1,high);
	}
	
}