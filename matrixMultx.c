#include <stdio.h>

int multMatrix(){
	int matrix1Rows = 0, matrix1Cols = 0, matrix2Rows = 0, matrix2Cols = 0;
	
	while (matrix1Rows < 1 || matrix1Cols < 1) {
		printf("Insert matrix 1 dimensions seperated by a space: ");
		scanf("%d %d", &matrix1Rows, &matrix1Cols);

		if (matrix1Rows < 1 || matrix1Cols < 1) {
			printf("Error: Dimensions must be greater than 0\n");		
		}
	}

	while((matrix1Cols != matrix2Rows) || (matrix1Rows < 1 || matrix1Cols < 1)) {
		printf("Insert matrix 2 dimensions seperated by a space: ");
		scanf("%d %d", &matrix2Rows, &matrix2Cols);

		if(matrix1Cols != matrix2Rows) {
			printf("\nThe row number of the second array does not match the column number in array 1");
		}
		else if (matrix1Rows < 1 || matrix1Cols < 1) {
			printf("Error: Dimensions must be greater than 0\n");		
		}
	}
	
	int matrix1[matrix1Rows][matrix1Cols];
	int matrix2[matrix2Rows][matrix2Cols];
	int resultMatrix[matrix1Rows][matrix2Cols];
	int i,j,k;

	printf("Input matrix 1 elements separated by spaces: ");

	for(i = 0; i < matrix1Rows; i++) {
		for(j = 0; j < matrix1Cols; j++) {
			scanf("%d",&matrix1[i][j]);
		}
	}

	printf("Input matrix 2 elements separated by spaces: ");

	for(i = 0; i < matrix2Rows; i++) {
		for(j = 0; j < matrix2Cols; j++) {
			scanf("%d", &matrix2[i][j]);
		}
	}
	
	printf("\nMatrix 1: \n");

	for(i = 0; i < matrix1Rows;i++) {
		for(j = 0; j < matrix1Cols; j++) {
			printf("%d \t", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrix 2: \n");

	for(i = 0; i < matrix2Rows; i++) {
		for( j = 0; j < matrix2Cols; j++) {
			printf("%d \t", matrix2[i][j]);
		}
		printf("\n");
	}

	printf("\nMultiplication Result:\n");

	for(i = 0; i < matrix1Rows; i++) {
		for(j = 0; j < matrix2Cols; j++) {
			resultMatrix[i][j] = 0;
			printf("Element [%d,%d] = ", i, j);
			for(k = 0; k < matrix1Cols; k++) {
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
				printf("%d*%d", matrix1[i][k], matrix2[k][j]);
				if(!(k == matrix1Cols - 1)){
					printf(" + ");
				}
			}
			printf(" = %d\n", resultMatrix[i][j]);
		}
	}
	
	printf("\nFinal Output: \n");
	for(i = 0; i < matrix1Rows; i++) {
		for(j = 0; j < matrix2Cols ; j++) {
			printf("%d \t", resultMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main() {
	multMatrix();
	return 1;
}