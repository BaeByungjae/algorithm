//2017029743_BaeByungJae_A

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int* A, * B;
	A = (int*)malloc(sizeof(int) * k);
	B = (int*)malloc(sizeof(int) * k);
	int* arr1 = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * m);
	int Countsum[100001];
	int* cnt = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &A[i], &B[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
		arr2[arr1[i]]++;

	}
	Countsum[0] = arr2[0];
	for (int i = 1; i <= m; i++) {
		Countsum[i] = Countsum[i - 1] + arr2[i];
	}

	for (int i = 0; i < k; i++) {
		cnt[i] = Countsum[B[i]] - Countsum[A[i] - 1];
	}
	for (int i = 0; i < k; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}