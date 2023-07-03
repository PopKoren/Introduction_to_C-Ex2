#define _CRT_SECURE_NO_WARNINGS
#define N 4

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
	Assigned by:
		Koren_Abugov #211480157
		Itay_Turiel #206397960
*/

/* Function declarations */

void Ex1();
void Ex2();
void Ex31();
void Ex32();
void Ex4();

/* Declarations of other sub-functions */

int* input_array(int);
int areReversed(int*, int*, int);
int findCommonDigit(unsigned long long, unsigned long long);
int moveDuplicatesV1(int*, int);
int moveDuplicatesV2(int*, int);
int validateArray(int*, int);



int compareInts(const void* a, const void* b);
int binarySearch(int* arr, int low, int high, int key);


/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : \n", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: do {
				select = 0;
				printf("Ex31--->1\n");
				printf("Ex32--->2\n");
				printf("please select 1-2 : \n");
				scanf("%d", &select);
			} while ((select < 1) || (select > 2));
			switch (select)
			{
			case 1: Ex31(); break;
			case 2: Ex32(); break;
			};
			break;
			case 4: Ex4(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

void Ex1() {
	int n = 0;
	int* A, * B;
	printf("please enter the size of arrays: \n");
	scanf("%d", &n);
	printf("please enter elements of the first array: \n");
	A = input_array(n);
	printf("please enter elements of the second array: \n");
	B = input_array(n);
	areReversed(A, B, n) ? printf("Arrays are the opposite to one another.\n") : printf("Arrays are not the opposite to one another.\n");
	free(A); free(B);
}

void Ex2() {
	unsigned long long n1, n2;
	int answer = -2;
	printf("please enter two integers (64 bits) sorted in ascending order to find a common digit\n: ");
	scanf("%llu%llu", &n1, &n2);
	answer = findCommonDigit(n1, n2);
	switch (answer)
	{
	case -2: printf("Error in function.\n"); break;
	case -1: printf("%llu and %llu has no common digit.\n", n1, n2); break;
	default: printf("%llu and %llu common digit from right is: %d\n", n1, n2, answer); break;
	}
}

void Ex31() {
	int n = 0, i, answer = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array ranging from -%d to %d: \n", n, n);
	A = input_array(n);
	printf("Array before moving duplications: \n");
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nArray after moving duplications: \n");
	answer = moveDuplicatesV1(A, n);
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nThe number of different elements in array: %d.\n", answer);
	free(A);
}

void Ex32() {
	int n = 0, i, answer = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array: \n");
	A = input_array(n);
	printf("Array before moving duplications: \n");
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nArray after moving duplications: \n");
	answer = moveDuplicatesV2(A, n);
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nThe number of different elements in array: %d.\n", answer);
	free(A);

}

void Ex4() {
	int n = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array: \n");
	A = input_array(n);
	validateArray(A, n) ? printf("Array contains all numbers from 0 to %d.\n", n - 1) : printf("Array doesn't contain all numbers from 0 to %d.\n", n - 1);
	free(A);
}

/* Sub-Function definitions */

int* input_array(int n) {
	int i;
	int* A = (int*)malloc(n * sizeof(int));
	assert(A);
	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", A + i);
	}
	return A;
}

int areReversed(int* A, int* B, int n) {
	if (n == 0)
	{
		return 1;
	}

	if (A[0] != B[n - 1])
	{
		return 0;
	}

	return areReversed(A + 1, B, n - 1);
}

int findCommonDigit(unsigned long long n1, unsigned long long n2) {
	if (n1 == 0 || n2 == 0) {
		return -1;
	}

	int d1 = n1 % 10;
	int d2 = n2 % 10;

	if (d1 == d2) {
		return d1;
	}

	if (d1 < d2) {
		return findCommonDigit(n1, n2 / 10);
	}

	return findCommonDigit(n1 / 10, n2);
}

int moveDuplicatesV1(int* arr, int n) {
	int* temp = (int*)malloc(sizeof(int) * n);
	assert(temp);
	int i, j = 0, k = n - 1;
	for (i = 0; i < n; i++) {
		int l;
		for (l = 0; l < i; l++) {
			if (arr[i] == arr[l]) {
				break;
			}
		}
		if (l == i) {
			temp[j] = arr[i];
			j++;
		}
		else {
			temp[k] = arr[i];
			k--;
		}
	}
	for (i = 0; i < n; i++) {
		arr[i] = temp[i];
	}
	free(temp);
	return j;
}

int moveDuplicatesV2(int* arr, int n) {

	int* copy = malloc(sizeof(int) * n);
	assert(copy);

	for (int i = 0; i < n; i++) {
		copy[i] = arr[i];
	}

	
	qsort(copy, n, sizeof(int), compareInts);

	int numUnique = 1;
	for (int i = 1; i < n; i++) {
		if (copy[i] != copy[i - 1]) {
			numUnique++;
		}
	}

	int uniqueIndex = 0;
	for (int i = 0; i < n; i++) {
		int pos = binarySearch(copy, 0, n - 1, arr[i]);
		if (pos > 0 && copy[pos] == copy[pos - 1]) {
			copy[n - uniqueIndex - 1] = arr[i];
			uniqueIndex++;
		}
		else {
			copy[pos] = arr[i];
		}
	}


	for (int i = 0; i < n; i++) {
		arr[i] = copy[i];
	}


	free(copy);


	return numUnique;

}

int validateArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{

		if (arr[i] < 0 || arr[i] >= n) {
			return 0;
		}

		
		int temp = arr[i];
		arr[i] = arr[temp];
		arr[temp] = temp;

	}

	
	for (int i = 0; i < n; i++) {
		if (arr[i] != i) {
			return 0;
		}
	}


	return 1;

}

/* ------------------- */

int binarySearch(int* arr, int low, int high, int key) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}




int compareInts(const void* a, const void* b) {
	int x = *((int*)a);
	int y = *((int*)b);
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	else {
		return 0;
	}
}

/* ------------------- */