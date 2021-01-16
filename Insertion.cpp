//2017029743_BaeByungJae_A
#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] < key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++)printf("%d\n", arr[i]);
	return 0;
}
