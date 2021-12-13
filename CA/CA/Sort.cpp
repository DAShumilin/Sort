#include "Swap_Min.h"
#include "Memory.h"

int* Bubble_Sort(int* arr, int N) {

	for (int i = 0; i < N - 2; ++i) {
		for (int j = 0; j < N - 2 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				Swap(&(arr[j]), &(arr[j + 1]));
			}
		}
	}
    return arr;
}

int* Insertion_Sort(int* arr, int N) {

	for (int i = 1; i < N - 1; ++i) {
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			Swap(&(arr[j]), &(arr[j + 1]));
			--j;
		}
	}
    return arr;
}

int* Merge_Sort(int* arr, int* arr_copy, int left, int right){

    if (left == right)
    {
        arr_copy[left] = arr[left];
        return arr_copy;
    }

    int middle = left + (right - left) / 2;

    int* l_buff = Merge_Sort(arr, arr_copy, left, middle);
    int* r_buff = Merge_Sort(arr, arr_copy, middle + 1, right);

    int* arr_end = l_buff == arr ? arr_copy : arr;

    int l_cur = left, r_cur = middle + 1;
    for (int i = left; i <= right; ++i){

        if (l_cur <= middle && r_cur <= right){

            if (l_buff[l_cur] < r_buff[r_cur]){
                arr_end[i] = l_buff[l_cur];
                l_cur++;
            }
            else{
                arr_end[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle){
            arr_end[i] = l_buff[l_cur];
            l_cur++;
        }
        else{
            arr_end[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return arr_end;
}