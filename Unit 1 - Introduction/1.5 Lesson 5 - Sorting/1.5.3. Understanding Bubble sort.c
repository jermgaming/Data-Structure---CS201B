#include<stdio.h>
void main() {
	int a[20], i, n, j, temp;
	printf("Enter value of n : ");
	scanf("%d", &n);
	for (int i=0;i<n;i++) { // Complete the code in for
		printf("Enter element for a[%d] : ", i);
		scanf("%d",&a[i]); // Complete the statement
	}
	printf("Before sorting the elements in the array are\n");
	for (int i=0;i<n;i++ ) { // Complete the code in for
		printf("Value of a[%d] = %d\n", i,a[i]); // Complete the statement
	}
	for (int i=0;i<n;i++ ) { // Complete the code in for
		for (int j=0;j<n-i-1;j++ ) { // Complete the code in for
			if (a[j]>a[j+1] ) { // Complete the condition part
				int temp=a[j];	 // Complete the statements to swap elements
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After sorting the elements in the array are\n");
	for ( int i=0;i<n;i++) { // Complete the code in for
		printf("Value of a[%d] = %d\n", i,a[i]); // Complete the statement
	}
}