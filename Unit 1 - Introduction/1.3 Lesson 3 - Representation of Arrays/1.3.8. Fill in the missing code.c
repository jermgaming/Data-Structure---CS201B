#include <stdio.h>
void main() {
	int arr[5][5], i, j, rows, cols, sum;
	printf("Enter row and column sizes : ");
	scanf("%d %d", &rows, &cols);
	for (   int i=0;i<rows;i++         ) { //Complete the code in for
		for (   int j=0;j<cols;j++        ) { //Complete the code in for
			printf("Enter the value of arr[%d][%d] : ", i, j);
			scanf(  "%d",&arr[i][j]      ); // Complete the statement
		}
	}
	printf("The given matrix is\n");
	for (   int i=0;i<rows;i++       ) { //Complete the code in for
		for (   int j=0;j<cols;j++          ) { //Complete the code in for
			printf("%d ",     arr[i][j]       ); // Complete the statement
		}
		printf("\n");
	}
	for (  int i=0;i<rows;i++      ) { //Complete the code in for
		sum =  0    ; // Complete the statement
		for (   int j=0;j<cols;j++         ) { //Complete the code in for
			sum =  sum+arr[i][j]          ; // Complete the statement
		}
		printf("Sum of row - %d elements = %d\n", i, sum);
	}
}