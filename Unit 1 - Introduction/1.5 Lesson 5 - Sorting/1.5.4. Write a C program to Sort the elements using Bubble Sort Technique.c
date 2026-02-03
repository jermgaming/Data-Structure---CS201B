#include<stdio.h>
void main() {
	int a[20], i, n, j, temp;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the for loop to read array elements
	
	for(int i=0;i<n;i++){
		printf("Enter element for a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	printf("Before sorting the elements in the array are\n");
	// Write the for loop to display array elements before sorting
	for(int i=0;i<n;i++){
		
		printf("Value of a[%d] = %d\n",i,a[i]);
	}

	//printf("\n");
	//Write the code to sort elements
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After sorting the elements in the array are\n");
	//fix the readme.md
	for(int i=0;i<n;i++){
		printf("Value of a[%d] = %d\n",i,a[i]);
	}
}