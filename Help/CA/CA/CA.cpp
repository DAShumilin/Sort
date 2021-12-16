#include <stdio.h>
#include <malloc.h>
#include "Swap_Min_Print_Worst_Arr.h"
#include "Memory.h"
#include "Sort.h"
#include <ctime>

int main() {

	int num_1;
	int num_2;
	int sort;
	int time_copy[3] = { 0 };
	int show_arr;
	int worst_arr;

	printf("Create the worst case?\n1. Yes\n2. No\n");
	scanf_s("%d", &worst_arr);
	
	printf("How many times do you want to enter the sizes of the arrays?\n");
	scanf_s("%d", &num_1);

	int* size = (int*)calloc(num_1, sizeof(int));
	int* time = (int*)calloc(num_1, sizeof(int));
	int* show_num = (int*)calloc(num_1, sizeof(int));

	if (worst_arr == 1) {
		printf("For the worst case, enter the value last\n");
	}
	for (int i = 0; i < num_1; ++i) {
		printf("What is the size of the array?\n");
		scanf_s("%d", &num_2);
		size[i] = num_2;
		printf("Output array elements?\n1. Yes\n2. No\n");
		scanf_s("%d", &show_arr);
		show_num[i] = show_arr;
	}
	
	printf("What sort of sort do you want to use?\n1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n");
	scanf_s("%d", &sort);
	printf("\n");

	for (int i = 0; i < num_1; ++i) {
		for (int j = 0; j < 3; ++j) {
			int* arr = (worst_arr == 1 && i == (num_1 - 1)) ? Worst_Arr(size[i]) : Memory(size[i]);
			int* L = (int*)calloc(size[i], sizeof(int));
			int* R = (int*)calloc(size[i] - size[i] / 2 + 1, sizeof(int));
			int start_time = clock();
			switch (sort) {
			case 1:
				Bubble_Sort(arr, size[i]);
				Print(arr, show_num, size, i, j);
				break;
			case 2:
				Insertion_Sort(arr, size[i]);
				Print(arr, show_num, size, i, j);
				break;
			case 3:
				MergeSort(arr, L, R, 0, size[i] - 1);
				Print(arr, show_num, size, i, j);
				break;
			default:
				break;
			}
			int end_time = clock();
			free(L);
			free(R);
			free(arr);
			time_copy[i] = end_time - start_time;
		}
		time[i] = Min(time_copy);
	}

	printf("\nAmount of elements\t| Time\t|\n");
	for (int i = 0; i < num_1; ++i) {
		printf("%d\t\t\t|%d\t|\n", size[i], time[i]);
	}

	free(time);
	free(size);
	return 0;
}