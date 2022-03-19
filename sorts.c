#include <iostream>
#define SIZE 10

void bouble_sort(int arr[]);
void choice_sort(int arr[]);
void insert_sort(int arr[]);
void count_sort(int arr[], int M);
void radix_sort (int arr[]);
void merge_sort(int arr[], int size);
void quick_sort(int arr[]);

int main() {
	int M = 5;
	int size = SIZE;
	int arr[SIZE] = {0, 1, 1, 3, 4, 2, 0, 3, 2, 4};
	//bouble_sort(arr);
	//choice_sort(arr);
	//insert_sort(arr);
	//count_sort(arr, M);
	//radix_sort (arr);
	merge_sort(arr, size);
	/*for(int i = 0; i < SIZE; ++i)
		cout << arr[i] << '\t';
	cout << '\n';*/
	return 0;
}

void bouble_sort(int arr[]) { //универсальная сортировка ПУЗЫРЬКОМ O(N^2)
	for(int j = 0; j < SIZE; ++j) {
		for(int i = 0; i < SIZE -1 - j; ++i) {
			if(arr[i] > arr[i+1]) {
				int perem = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = perem;
			}			
		}
	}
}

void choice_sort(int arr[]) { //универсальная сортировка ВЫБОРОМ O(N^2)
	for(int i = 0; i < SIZE-1; ++i) {
		for(int j = i + 1; j < SIZE; ++j) {
			if (arr[j] < arr[i]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void insert_sort(int arr[]) { //универсальная сортировка ВСТАВКАМИ O(N^2)
	for(int pos = 1; pos < SIZE; ++pos) {
		int i = pos;
		while (arr[i-1] > arr[i] && i > 0) {
			int tmp = arr[i-1];
			arr[i-1] = arr[i];
			arr[i--] = tmp;
		}
	}
}

void count_sort(int arr[], int M) { //не является универсальной, подходит для малого разброса значений элементов в массиве, сортировка ПОДСЧЕТОМ O(N)
	int new_arr[M] ={0};
	for(int i =0; i < SIZE; ++i) {
		++new_arr[arr[i]];
	}
	for(int x = 0, i = 0; x < M; ++x) {
		for(int k = 0; k < new_arr[x]; ++k, ++i) {
			arr[i] = x;
		}
	}
}

void radix_sort (int arr[]) { // поразрядная сортировка, почти универсальная O(N)
	int* a0 = new int[SIZE];
	int* a1 = new int[SIZE];
	for(int radix; radix < 32; ++radix) {
		int a0_size = 0;
		int a1_size = 0;
		for(int i = 0; i < SIZE; ++i) {
			if((arr[i] & (1 << radix)) == 0) {
				a0[a0_size++] = arr[i];
			} else {
				a1[a1_size++] = arr[i];
			}
		}
		for(int i = 0; i < a0_size; ++i) {
			arr[i] = a0[i];
		}
		for (int i =0; i < a1_size; ++i) {
			arr[a0_size + i] = a1[i];
		}
	}
	delete[] a0;
	delete[] a1;
}

void merge_sort(int arr[], int size) { // Сортировка слиянием, универсальная сортировка O(n*log2(n))
	using namespace std;
	int middle = size / 2;
	int* left_arr = arr;
	int* right_arr = arr + middle;
	int left_size = middle;
	int right_size = size - middle;
	merge_sort(left_arr, left_size);
	merge_sort(right_arr, right_size);
	int* buffer = new int[size];
	int left_index = 0;
	int right_index = 0;
	int buffer_index = 0;
	while (left_index < left_size && right_index < right_size) {
		if (left_arr[left_index] <= right_arr[right_index]) {
			buffer[buffer_index] = left_arr[left_index];
			buffer_index++;
			left_index++;
		} else {
			buffer[buffer_index] = right_arr[right_index];
			buffer_index++;
			right_index++;
		}
	}
	while (left_index < left_size) {
		buffer[buffer_index] = left_arr[left_index];
		buffer_index++;
		left_index++;
	}
	while (right_index < right_size) {
		buffer[buffer_index] = right_arr[right_index];
		buffer_index++;
		right_index++;
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = buffer[i];
	}
	delete[] buffer;
}

void quick_sort(int arr[]) {
	
}