//2017029743_BaeByungJae_A
#include<stdio.h>
#include<stdlib.h>

int N, arr[1000001];
int* arr2;
void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] >= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}
	int tmp = i > mid ? j : i;
	while (k <= right)arr2[k++] = arr[tmp++];
	for (int i = left; i <= right; i++)arr[i] = arr2[i];
}
void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}
int main() {
	scanf("%d", &N);
	arr2 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	merge_sort(0, N - 1);
	for (int i = 0; i < N; i++)printf("%d\n", arr[i]);
	return 0;
}