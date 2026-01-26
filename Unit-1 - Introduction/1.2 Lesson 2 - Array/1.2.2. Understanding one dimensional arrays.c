#include <stdio.h>
void main() {
	int a[10], i, n;
	printf("Enter how many values you want to read : ");
	scanf("%d",&n ); // Complete the code
	for (i=0 ; i<n ; i ++) { // Complete the code
		printf("Enter the value of a[%d] : ", i);
		scanf("%d", &a[i]); // Complete the code
	}
	printf("The array elements are : ");
	for (i=0 ; i<n ; i++ ) { // Complete the code
		printf(" %d ", a[i]); // Complete the code
	}
}