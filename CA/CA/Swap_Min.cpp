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