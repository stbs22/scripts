// C program for Fibonacci Search 
#include <stdio.h> 

// Utility function to find minimum of two elements 
int min(int x, int y) { return (x<=y)? x : y; } 

/* Returns index of x if present, else returns -1 */
int fibonacci_search(int arr[], int x, int n) 
{ 
	/* Initialize fibonacci numbers */
	int fibm2 = 0; // (m-2)'th Fibonacci No. 
	int fibm1 = 1; // (m-1)'th Fibonacci No. 
	int fibM = fibm2 + fibm1; // m'th Fibonacci 

	/* fibM is going to store the smallest Fibonacci 
	Number greater than or equal to n */
	while (fibM < n) 
	{ 
		fibm2 = fibm1; 
		fibm1 = fibM; 
		fibM = fibm2 + fibm1; 
	} 

	// Marks the eliminated range from front 
	int offset = -1; 

	/* while there are elements to be inspected. Note that 
	we compare arr[fibMm2] with x. When fibM becomes 1, 
	fibMm2 becomes 0 */
	while (fibM > 1) 
	{ 
		// Check if fibMm2 is a valid location 
		int i = min(offset+fibm2, n-1); 

		/* If x is greater than the value at index fibMm2, 
		cut the subarray array from offset to i */
		if (arr[i] < x) 
		{ 
			fibM = fibm1; 
			fibm1 = fibm2; 
			fibm2 = fibM - fibm1; 
			offset = i; 
		} 

		/* If x is greater than the value at index fibMm2, 
		cut the subarray after i+1 */
		else if (arr[i] > x) 
		{ 
			fibM = fibm2; 
			fibm1 = fibm1 - fibm2; 
			fibm2 = fibM - fibm1; 
		} 

		/* element found. return index */
		else return i; 
	} 

	/* comparing the last element with x */
	if(fibm1 && arr[offset+1]==x)return offset+1; 

	/*element not found. return -1 */
	return -1; 
} 

/* driver function */
int main(void) 
{ 
	int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 
				85, 90, 100}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int x = 40; 
	printf("Found at index: %d\n", 
			fibonacci_search(arr, x, n)); 
	return 0; 
} 
