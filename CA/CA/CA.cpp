#include <stdio.h>
#include <malloc.h>
#include "Swap_Min.h"
#include "Memory.h"
#include "Sort.h"
#include <ctime>

int main() {

	int num_1;
	int num_2;
	int sort;
	int time_copy[3] = { 0 };

	printf("How many times do you want to enter the sizes of the arrays?\n");
	scanf_s("%d", &num_1);
	int* size = (int*)calloc(num_1, sizeof(int));
	int* time = (int*)calloc(num_1, sizeof(int));

	for (int i = 0; i < num_1; ++i) {
		printf("What is the size of the array?\n");
		scanf_s("%d", &num_2);
		size[i] = num_2;
	}

	printf("What sort of sort do you want to use?\n1.Bubble Sort\n2.Insertion Sort\n3.Merge Sort\n");
	scanf_s("%d", &sort);

	for (int i = 0; i < num_1; ++i) {
		for (int j = 0; j < 3; ++j) {
			int* arr = Memory(size[i]);
			int* arr_copy = (int*)calloc(size[i], sizeof(int));
			int start_time = clock();
			switch (sort) {
			case 1:
				Bubble_Sort(arr, size[i]);
				break;
			case 2:
				Insertion_Sort(arr, size[i]);
				break;
			case 3:
				Merge_Sort(arr, arr_copy, 0, size[i] - 1);
				break;
			default:
				break;
			}
			int end_time = clock();
			free(arr_copy);
			free(arr);
			time_copy[i] = end_time - start_time;
		}
		time[i] = Min(time_copy);
	}

	printf("Amount of elements\t| Time\t|\n");
	for (int i = 0; i < num_1; ++i) {
		printf("%d\t\t\t|%d\t|\n", size[i], time[i]);
	}

	free(time);
	free(size);
	return 0;
}