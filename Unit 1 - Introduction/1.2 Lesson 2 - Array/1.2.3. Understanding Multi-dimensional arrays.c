#include <stdio.h>
void main() {
	int a[5][5], i, j, rows, cols;
	printf("Enter row and column sizes : ");
	scanf("%d %d", &rows,&cols ); //Correct the code
	for (i =0 ; i <rows ; i++  ) { //Correct the code
		for (j =0 ; j<cols  ; j++) { //Correct the code
			printf("Enter the value of a[%d][%d] : ", i, j);
			scanf("%d", &a[i][j] ); //Correct the code
		}
	}
	printf("The given matrix is\n");
	for (i=0 ; i<rows ; i++ ) { //Correct the code
		for (j=0 ; j<cols ; j++ ) { //Correct the code
			printf("%d ",a[i][j] ); //Correct the code
		}
		printf("\n");
	}
}