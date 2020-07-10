// C++ program to find rank of a matrix 
#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 3 

/* function for exchanging two rows of 
a matrix */
void swap(int mat[R][C], int row1, int row2, 
		int col) 
{ 
	for (int i = 0; i < col; i++) 
	{ 
		int temp = mat[row1][i]; 
		mat[row1][i] = mat[row2][i]; 
		mat[row2][i] = temp; 
	} 
} 

// Function to display a matrix 
void display(int mat[R][C], int row, int col); 

/* function for finding rank of matrix */
int rankOfMatrix(int mat[R][C]) 
{ 
	int rank = C; 

	for (int row = 0; row < rank; row++) 
	{ 
		// Before we visit current row 'row', we make 
		// sure that mat[row][0],....mat[row][row-1] 
		// are 0. 

		// Diagonal element is not zero 
		if (mat[row][row]) 
		{ 
		for (int col = 0; col < R; col++) 
		{ 
			if (col != row) 
			{ 
				// This makes all entries of current 
				// column as 0 except entry 'mat[row][row]' 
				double mult = (double)mat[col][row] / 
									mat[row][row]; 
				for (int i = 0; i < rank; i++) 
				mat[col][i] -= mult * mat[row][i]; 
			} 
		} 
		} 

		// Diagonal element is already zero. Two cases 
		// arise: 
		// 1) If there is a row below it with non-zero 
		// entry, then swap this row with that row 
		// and process that row 
		// 2) If all elements in current column below 
		// mat[r][row] are 0, then remvoe this column 
		// by swapping it with last column and 
		// reducing number of columns by 1. 
		else
		{ 
			bool reduce = true; 

			/* Find the non-zero element in current 
				column */
			for (int i = row + 1; i < R; i++) 
			{ 
				// Swap the row with non-zero element 
				// with this row. 
				if (mat[i][row]) 
				{ 
					swap(mat, row, i, rank); 
					reduce = false; 
					break ; 
				} 
			} 

			// If we did not find any row with non-zero 
			// element in current columnm, then all 
			// values in this column are 0. 
			if (reduce) 
			{ 
				// Reduce number of columns 
				rank--; 

				// Copy the last column here 
				for (int i = 0; i < R; i ++) 
					mat[i][row] = mat[i][rank]; 
			} 

			// Process this row again 
			row--; 
		} 

	// Uncomment these lines to see intermediate results 
	// display(mat, R, C); 
	// printf("\n"); 
	} 
	return rank; 
} 

/* function for displaying the matrix */
void display(int mat[R][C], int row, int col) 
{ 
	for (int i = 0; i < row; i++) 
	{ 
		for (int j = 0; j < col; j++) 
			printf(" %d", mat[i][j]); 
		printf("\n"); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
int mat[][3] = {{10, 20, 10}, 
				{-20, -30, 10}, 
				{30, 50, 0}}; 
	printf("Rank of the matrix is : %d", 
		rankOfMatrix(mat)); 
	return 0; 
} 

