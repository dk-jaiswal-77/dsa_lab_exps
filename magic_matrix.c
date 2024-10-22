#include <stdio.h>

int main() {
  int n;
  printf("Enter length of matrix (odd number of rows/cols): ");
  scanf("%d", &n);

  // Initialize the matrix with zeros
  int matrix[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = 0;
    }
  }

  // Start at the middle of the last row
  int currRow = n - 1;
  int currCol = n / 2;
  int prevRow, prevCol;
  int size  = n * n;

  for (int i = 1; i <= size; i++) {
    // If the current position is occupied, move to the cell above the previous one
    if (matrix[currRow][currCol] != 0) {
      currRow = prevRow - 1;
      currCol = prevCol;
    }

    // Now, the current position is empty, so place the value
    matrix[currRow][currCol] = i;

    // Update previous row and column
    prevRow = currRow;
    prevCol = currCol;

    // Determine new current position
    currRow = (currRow + 1) % n;  // Move to the next row, wrap around using modulo
    currCol = (currCol + 1) % n;  // Move to the next column, wrap around using modulo
  }

  // Print the matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", matrix[i][j]);  // Formatting for better readability
    }
    printf("\n");
  }

  return 0;
}