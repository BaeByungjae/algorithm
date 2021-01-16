//2017029743_BaeByungJae_A

#include<stdio.h>
#include<stdlib.h>
int size = 0, arr[100001];

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int here, int size) {
	int left = here * 2;
	int right = here * 2 + 1;
	int max = here;
	if (left <= size && arr[left] >= arr[max])
		max = left;
	if (right <= size && arr[right] >= arr[max])
		max = right;
	if (max != here) {
		swap(&arr[here], &arr[max]);
		heapify(arr, max, size);
	}
}
void buildMaxHeap(int arr[], int size) {
	int a = size / 2;
	for (int i = a; i >= 1; i--) {
		heapify(arr, i, size);
	}
}

void insert(int* heap, int item) {
	int i;
	i = ++(size);
	while ((i > 1) && (item >= heap[i / 2])) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

int main() {
	int* heap = (int*)malloc(sizeof(int) * 110000);
	int n, m, a = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else if (n == 1) {
			scanf("%d", &m);
			insert(heap, m);
		}
		else if (n == 2) {
			if (size <= 0)break;
			int tmp = heap[1];
			heap[1] = heap[size--];
			arr[a++] = tmp;
			heapify(heap, 1, size);
		}
		else if (n == 3) {
			if (size == 0)break;
			int k;
			scanf("%d %d", &m, &k);
			if (m == 0)return 0;
			if (m > size)continue;
			if (heap[m] == k)continue;
			int tmp = heap[m];
			heap[m] = k;
			if (tmp > k)heapify(heap, m, size);
			else {
				int k = m;
				while ((m > 1) && (heap[m] >= heap[m / 2])) {
					swap(&heap[m], &heap[m / 2]);
					m /= 2;
				}
			}
		}
	}
	for (int i = 0; i < a; i++)printf("%d ", arr[i]);
	printf("\n");
	for (int i = 1; i <= size; i++)printf("%d ", heap[i]);
	printf("\n");
}
