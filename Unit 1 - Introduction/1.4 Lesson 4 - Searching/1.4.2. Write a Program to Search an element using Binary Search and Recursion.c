void read1(int arr[],int size){
	printf("Enter %d elements : ",size);
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
}

void bubbleSort(int arr[],int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void display(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int binarySearch(int arr[],int start,int end,int key){
	//base case
	if(start>end){
		return -1;
	}
	int mid=(start+end)/2;
	if(arr[mid]==key){
		return mid;
	}
	if(arr[mid]>key){
		return binarySearch(arr,start,mid-1,key);
	}
	return binarySearch(arr,mid+1,end,key);
}