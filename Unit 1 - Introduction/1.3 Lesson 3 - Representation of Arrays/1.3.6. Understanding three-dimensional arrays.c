#include <stdio.h>
void main() {
	int a[3][3][3], i, j, row, cols, pages, k;
	printf("Enter page, row and column sizes : ");
	scanf("%d %d %d", &pages,&row,&cols ); // Correct the code
	for (int i=0;i<pages;i++ ) { // Correct the code
		for ( int j=0;j<row;j++) { // Correct the code
			for ( int k=0;k<cols;k++) { // Correct the code
				printf("Enter the value of a[%d][%d][%d] : ", i, j, k);
				scanf("%d", &a[i][j][k] ); // Correct the code
			}
		}
	}
	for (int i=0;i<pages;i++ ) { // Correct the code
		for ( int j=0;j<row;j++) { // Correct the code
			for ( int k=0;k<cols;k++) { // Correct the code
				printf("The value of a[%d][%d][%d] : %d\n", i, j, k,a[i][j][k]  ); // Correct the code
			}
		}
	}

	
}