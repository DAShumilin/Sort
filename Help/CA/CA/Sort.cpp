#include "Swap_Min_Print_Worst_Arr.h"
#include "Memory.h"

void Bubble_Sort(int* arr, int N) {

	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < N - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				Swap(&(arr[j]), &(arr[j + 1]));
			}
		}
	}
}

void Insertion_Sort(int* arr, int N) {

	for (int i = 0; i < N; ++i) {
        int j = i - 1;
        int k = arr[i];
        while (arr[j] > k && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = k;
	}
}

void Merge_Sort(int* arr, int* L, int* R, int left, int middle, int right){

    int i, j, k;
    int l_a = middle - left + 1;
    int r_a = right - middle;

    for (i = 0; i < l_a; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < r_a; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = left; 

    while (i < l_a && j < r_a) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }

        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < l_a) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < r_a) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* arr, int* L, int* R, int left, int right){

    if (left < right) {

        int middle = left + (right - left) / 2;

        MergeSort(arr, L, R, left, middle);
        MergeSort(arr, L, R, middle + 1, right);

        Merge_Sort(arr, L, R, left, middle, right);
    }
}