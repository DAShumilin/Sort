#include <malloc.h>
#include <time.h>
#include <stdlib.h>

int* Memory(int N) {

	int* tmp = (int*)calloc(N, sizeof(int));

	srand(time(NULL));
	for (int i = 0; i < N; ++i) {
		tmp[i] = rand() % 10000;
	}

	return tmp;
}