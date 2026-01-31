#include <stdio.h>
void main() {
	int arr[20], number, sum = 0, min = 0, max = 0;
	scanf("%d", &number);
	printf("Elements: ");
	for (int i = 0; i < number; i++) {
		scanf("%d", &arr[i]);	
	}
	/* Write your logic here to find the maximum, minimum and average in the given integer array*/
	min=arr[0];
	float avg=0.00;
	for(int i=0;i<number;i++){
		avg+=arr[i];
		if(arr[i]<min){
			min=arr[i];
		}
		if(arr[i]>max){
			max=arr[i];
		}
	}
	avg=avg/number;
	
	printf("Min,max,avg: %d %d %0.2f",min,max,avg );
}