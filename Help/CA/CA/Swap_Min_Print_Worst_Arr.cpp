#include <stdio.h>
#include <malloc.h>

void Swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

int Min(int* arr) {

	int* min = arr;

	for (int i = 0; i < 2; ++i) {
		if (*min < arr[i + 1]) {
			*min = arr[i + 1];
		}
	}
	return *min;
}

int Min(int* a, int* b) {
	int tmp;

	if (*a == *b) {
		tmp = *a;
	}
	else {
		tmp = *a > *b ? *b : *a;
	}
	return tmp;
}

void Print(int* arr, int* show_num, int* size, int i, int j) {
	if (show_num[i] == 1 && j == 2) {
		for (int n = 0; n < size[i]; ++n) {
			printf("%d ", arr[n]);
		}
		printf("\n");
	}
}

int* Worst_Arr(int num) {
	int* arr = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; ++i) {
		arr[i] = num - 1;
		--num;
	}
	return arr;
}